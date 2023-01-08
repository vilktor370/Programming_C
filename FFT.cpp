#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char** argv){
    Mat image = imread("../Lenna.png", 1);
    imshow("image", image);
    waitKey(0);
}