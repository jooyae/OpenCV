#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

void MatOp1();


int main() {

	MatOp1();
	
	return 0;

}


void MatOp1() {

	//입력영상 img1_before 크기 256x256 출력 
	Mat img1 = imread("lenna.bmp");
	resizeWindow("img1", 256, 256);
	namedWindow("img1_before");
	imshow("img1_before", img1);

	// 출력영상 img1_after 상하좌우 녹색띠 25 만큼 
	Mat img2 = img1;
	Mat img3;
	img3 = img1;
	int borderSize = 25;
	copyMakeBorder(img2, img3,25, 25, 25, 25, BORDER_CONSTANT,Scalar(0,255,0));
	namedWindow("img1_after");
	//resizeWindow("img3", 231, 231);
	imshow("img1_after", img3);
	

	waitKey();
	destroyAllWindows();

}
