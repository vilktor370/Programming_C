#include <opencv2/opencv.hpp>
using namespace cv;
#include <iostream>
using std::cout;
using std::endl;
int main(){
    Mat img1 = imread("/Users/haochenyu/Desktop/Programming_C/Lenna.png", 1);
    Mat img2 = imread("/Users/haochenyu/Desktop/Programming_C/prince_book.jpg", 1);
    Mat resize_img1, resize_img2;
    Size size(300,300);
    cv::resize(img1, resize_img1, size);
    cv::resize(img2, resize_img2, size);
    Mat output = resize_img1 * 0.3 + resize_img2 + 0.7;
    imshow("Image", output);
    waitKey(0);

}