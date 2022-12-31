
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using std::cout;
using std::vector;
const int slider_max = 300;
int alpha_slider;
int beta_slider;
double alpha;
double beta;

Mat src;
Mat dst;

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
	// printf("Max index: %d total index: %lu\n", maxContourIndex, contours.size());
    drawContours(image, contours, -1, Scalar(0, 0, 255), 5);
	return image;
}

static void on_trackbar( int, void* )
{
   alpha = alpha_slider;
   beta = beta_slider;
   Mat result = detect(src.clone(), alpha, beta );
   printf("Lower %f Upper %f\n", alpha, beta);
   imshow( "Canny Edge Detection",result);
}
int main( void )
{
   src = imread("/Users/haochenyu/Desktop/Programming_C/prince_book.jpg");
   if( src.empty() ) { cout << "Error loading src1 \n"; return -1; }
   alpha_slider = 0;
   beta_slider = 0;
   namedWindow("Canny Edge Detection", WINDOW_AUTOSIZE); // Create Window
   createTrackbar( "Lower Threshold", "Canny Edge Detection", &alpha_slider, slider_max, on_trackbar );
   createTrackbar( "Higher Threshold", "Canny Edge Detection", &beta_slider, slider_max, on_trackbar );
   on_trackbar( alpha_slider, 0 );
   on_trackbar(beta_slider, 0);
   waitKey(0);
   return 0;
}