#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

void MatOp1();
void MatOp2();


int main() {

	MatOp1();
	MatOp2();
	
	return 0;

}


void MatOp1() {

	//�Է¿��� img1_before ũ�� 256x256 ��� 
	Mat img1 = imread("lenna.bmp");
	Mat img2 = img1;
	Mat img3;
	img3 = img1;
	resizeWindow("img1", 256, 256);
	namedWindow("img1_before");
	imshow("img1_before", img1);

	//����ũ ���� 
	Mat img(256, 256, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(128, 128), 100, Scalar(0, 0, 0), -1, LINE_AA);
	resizeWindow("img", 256, 256);
	namedWindow("mask");
	imshow("mask", img);


	// ��¿��� 
	//���� �� , ���� : ��� 
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("img", IMREAD_COLOR);

	
	src.setTo(Scalar(0, 255, 0), mask);

	imshow("img1_after", src);
	//imshow("mask", mask);

	waitKey();
	destroyAllWindows();

}

void MatOp2() {
	//���� �̹��� ��� ǥ�� & ũ�� ���� 
	Mat img4 = imread("lenna.bmp",128);
	namedWindow("img2_before");
	imshow("img2_before", img4);
	resizeWindow("img4", 256, 256);
	

	//���� ��� �̹��� �� ����ũ 
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat mask = imread("img4", IMREAD_GRAYSCALE);
	//��� ������ 
	src.setTo(Scalar(0, 0, 0), mask);
	imshow("img2_after", src);
	waitKey();
	destroyAllWindows();
}
