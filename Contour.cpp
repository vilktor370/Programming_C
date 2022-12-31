#include <opencv2/opencv.hpp>

#include <iostream>
#include <vector>

#include "Common.h"

// STL
using std::cout;
using std::endl;
using std::vector;
// OpenCV
using namespace cv;

int main(int argc, char ** argv){
    Mat gray = load("/Users/haochenyu/Desktop/Programming_C/Lenna.png", 0);
    Mat color = load("/Users/haochenyu/Desktop/Programming_C/Lenna.png", 1);
    Mat bin = binary(gray, 127);
    
    /*
    cv::RETR_TREE = 3;
    cv::CHAIN_APPROX_NONE = 1;
    cv::CHAIN_APPROX_SIMPLE = 2;
    */
    vector<Mat> contours;
    cv::findContours(bin, contours, 3, 2);
    int maxIndex = -1;
    int maxSize = 0;
    for(int i =0; i < contours.size(); i++){
        int row = contours[i].rows;
        if( row > maxSize){
            maxSize = row;
            maxIndex = i;
        }
    }

    cout << maxIndex <<"\n"<< maxSize<< endl;
    Mat draw_img = color.clone();
    cv::drawContours(draw_img, contours, maxIndex, Scalar(0, 255, 0), 1);
    imshow("image", draw_img);
    waitKey(0);
}