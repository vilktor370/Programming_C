#include <opencv2/opencv.hpp>

#include "Common.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char** argv){
    Mat temp = load("/Users/haochenyu/Desktop/Programming_C/Lenna_face.png", 1);
    Mat color = load("/Users/haochenyu/Desktop/Programming_C/Lenna.png", 1);
    cout << temp.rows <<" "<< temp.cols << endl;
    cout << color.rows <<" "<< color.cols << endl;
    /*
        TM_SQDIFF        = 0, small is closer
        TM_SQDIFF_NORMED = 1, closer to 0 is better
        TM_CCORR         = 2, large is closer
        TM_CCORR_NORMED  = 3, closer to 1 is better
        TM_CCOEFF        = 4, large is closer
        TM_CCOEFF_NORMED = 5  closer to 1 is better
    */
    Mat result;
    cv::matchTemplate(color, temp, result, 1);
    int w = result.cols, h = result.rows;
    double min_val, max_val;
    Point min_loc, max_loc;
    cv::minMaxLoc(result, &min_val, &max_val, &min_loc, &max_loc);
    // Since TM_SQDIFF is used, we would like to find minimum value
    Mat draw_img = color.clone();
    Point top_left = min_loc; // will be max_loc if other methods are used
    /*
    
    top_left ---------
    |           w
    |
    |h
    |
    |                bottom_right
    */
    Point bottom_right(top_left.x * w, top_left.y * h);
    cv::rectangle(draw_img, Rect(top_left, bottom_right), Scalar(0, 0, 255), 2);

    imshow("image", draw_img);
    waitKey(0);
}