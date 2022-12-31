#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace cv;


int alpha_slider;
double alpha;
double beta;

Mat image;



static Mat detect(Mat image, int lowThreshold, int highThreshold){

	
	Mat gray;
	cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

	Mat edges;
    int kernelSize = 3;
    bool L2gradient = false;
    cv::Canny(gray, edges, lowThreshold, highThreshold, kernelSize, L2gradient);


    vector<vector<cv::Point> > contours;
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
    drawContours(image, contours, -1, Scalar(0, 0, 255), 5);
	return image;
}

int main(){
	char *filename = "/Users/haochenyu/Desktop/Programming_C/prince_book.jpg";
	image = imread(filename);
	if(image.empty()) return -1;


	Mat result = detect(image, 243, 291);

    
	cv::namedWindow("Image Viewer", cv::WINDOW_NORMAL);
	imshow("Image", result);
	waitKey(0);
	return 0;
}
