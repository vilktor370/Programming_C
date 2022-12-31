#include <opencv2/opencv.hpp>

#include <iostream>
#include "Common.h"
using std::cout;
using std::endl;
using namespace cv;

int main(int argc, char ** argv){
    Mat img= imread("/Users/haochenyu/Desktop/Programming_C/Lenna.png", 0);
    if (img.empty()){
        cout << "Image not read\n";
        return -1;
    }

    Mat result;
    // cv::findContours(img, result, cv::RETR_TREE, )

    Mat bin = binary(img, 127);
    imshow("image", bin);
    waitKey(0);
}