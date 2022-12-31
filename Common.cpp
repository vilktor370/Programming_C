#include "Common.h"


Mat binary(Mat& input_img, int THREHOLD){
    /*
        input: Gray scale Mat, threshold value
        output: hard-binarized Mat
    */
    if(input_img.empty()){
        CV_Error(0, "Input image is empty!");
        return Mat();
    }
    int rows = input_img.rows;
    int cols = input_img.cols;
    Mat bin_img(rows, cols, CV_8UC1, Scalar(255));
    for(int i =0; i< rows;++i){
        for (int j =0;j< cols;++j){
            if (input_img.at<uchar>(i, j) < THREHOLD){
                bin_img.at<uchar>(i, j) = 0;
            }
        }// end cols
    }// end rows
    return bin_img;

}