#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using namespace cv;


static Mat detect(Mat image, int lowThreshold, int highThreshold){

	
	Mat gray;
	cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

	Mat edges;
    int kernelSize = 3;
    bool L2gradient = false;
    cv::Canny(gray, edges, lowThreshold, highThreshold, kernelSize, L2gradient);


    vector<vector<cv::Point>> contours;
    findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    double maxContourArea = 0;
    int maxContourIndex = -1;
    for(int i =0;i< contours.size();++i){
        double currArea = contourArea(contours[i]);
        if (currArea > maxContourArea){
            maxContourArea = currArea;
            maxContourIndex = i;
        }
    }
	printf("Max index: %d total index: %lu\n", maxContourIndex, contours.size());
    drawContours(image, contours, maxContourIndex, Scalar(0, 0, 255), 5);
	return image;
}

int main(int argc, char**argv){
    Mat image = imread("/Users/haochenyu/Desktop/Programming_C/prince_book.jpg", 1);
    if(image.empty()){return -1;}
    /*
    1--3
    |  |
    2--4
    */
    Point2f pts1[] = {
        Point2f(744, 352),
        Point2f(659, 991),
        Point2f(1462, 340),
        Point2f(1572, 989)
    };

    int height = pts1[3].x - pts1[0].x;
    int width = pts1[3].y - pts1[0].y;
    Point2f pts2[] = {
        Point2f(0, 0),
        Point2f(0, height),
        Point2f(width, 0),
        Point2f(width, height)
    };


    Mat matrix = cv::getPerspectiveTransform(pts1, pts2);

    Mat warp;
    cv::warpPerspective(image, warp, matrix, Size(width, height));

    Mat result = detect(warp, 243, 291);



    imshow("Homography", result); 
    waitKey(0);
}