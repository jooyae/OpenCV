#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

void MatOp1();
void MatOp2();
void MatOp3();
void MatOp4();
void MatOp5();
void MatOp6();
void MatOp7();
void ScalarOp();
void InputArrayOp();
void printMat(InputArray _mat);
void camera_in();
void camer_in_video_out();
void drawLines();



int main(void) {

	//MatOp1();
	//MatOp2();
	//MatOp3();
	//MatOp4();
	//MatOp5(); 
	//MatOp6();
	//MatOp7();
	//ScalarOp();
	//InputArrayOp();
	//camera_in();
	//camer_in_video_out();
	drawLines();
	return 0;

}


void MatOp1() {

	//입력영상 img1_before 크기 256x256 출력 
	Mat img1 = imread("lenna.bmp");
	Mat img2 = img1;
	Mat img3;
	img3 = img1;
	resizeWindow("img1", 256, 256);
	namedWindow("img1_before");
	imshow("img1_before", img1);

	//마스크 영상 
	Mat img(256, 256, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(128, 128), 100, Scalar(0, 0, 0), -1, LINE_AA);
	resizeWindow("img", 256, 256);
	namedWindow("mask");
	imshow("mask", img);


	// 출력영상 
	//레나 원 , 배경색 : 녹색 
	Mat src = imread("lenna.bmp", IMREAD_COLOR);
	Mat mask = imread("img", IMREAD_COLOR);

	
	src.setTo(Scalar(0, 255, 0), mask);

	imshow("img1_after", src);
	//imshow("mask", mask);

	waitKey();
	destroyAllWindows();

}

void MatOp2() {
	Mat img1 = imread("dog.bmp");
	Mat img2 = img1;
	Mat img3;
	img3 = img1;

	Mat img4 = img1.clone();
	Mat img5;
	img1.copyTo(img5);

	img1.setTo(Scalar(0, 255, 255));

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);
	imshow("img4", img4);
	imshow("img5", img5);

	waitKey();
	destroyAllWindows();
}

void MatOp3() {
	Mat img1 = imread("cat.bmp");

	if (img1.empty()) {
		cerr << "Image load failed" << endl;
		return;
	}

	Mat img2 = img1(Rect(220, 120, 340, 240));
	Mat img3 = img1(Rect(220, 120, 340, 240)).clone();

	img2 = ~img2;

	imshow("img1", img1);
	imshow("img2", img2);
	imshow("img3", img3);

	waitKey();
	destroyAllWindows();
}
void MatOp4() {
	Mat mat1 = Mat::zeros(3, 4, CV_8UC1);

	for (int j = 0; j < mat1.rows; j++) {
		for (int i = 0; i < mat1.cols; i++) {
			mat1.at<uchar>(j, i)++;
		}
	}
	//professor 
	uchar& v1 = mat1.at<uchar>(1, 2); //at은 값을 참조로 반환 
	v1 = 5;								// v1변경 -> (1,2) 화소값 변경 
	mat1.at<uchar>(1, 3) = 7;
	cout << "mat1(at):/n" << mat1 << endl; // at은 한번에 

	for (int j = 0; j < mat1.rows; j++) {
		uchar* p = mat1.ptr<uchar>(j);  //1
		for (int i = 0; i < mat1.cols; i++) {
			p[i]++;    //2 ptr은 두번에 나눠서 
		}
	}
	//3번째 MatIterator 
	for (MatIterator_<uchar> it = mat1.begin<uchar>(); it != mat1.end<uchar>(); ++it) {
		(*it)++; //it이 가리키는 값 
	}
	cout << "mat1:/n" << mat1 << endl;
}
void MatOp5() {
	Mat img1 = imread("lenna.bmp");

	cout << "Width: " << img1.cols << endl;
	cout << "Height:" << img1.rows << endl;
	cout << "Channels: " << img1.channels() << endl;

	//professor 
	cout << "Depth: " << img1.depth() << endl;
	cout << "ElemSize: " << img1.elemSize() << " bytes" << endl;
	cout << "ElemSize1: " << img1.elemSize1() << " bytes" << endl;
	cout << "Size: " << img1.size << " or " << img1.size() << endl;
	cout << "Size[0]: " << img1.size[0] << ",Size[1]: " << img1.size[1] << endl;
	cout << "Total: " << img1.total() << " = " << img1.size[0] << "x" << img1.size[1] << endl;

 	if (img1.type() == CV_8UC1)
		cout << "img5 is a grayscale image." << endl;
	else if (img1.type() == CV_8UC3)
		cout << "img5 is a truecolor image." << endl;

	float data[] = { 2.f, 1.414f, 3.f, 1.732f };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:/n" << mat1 << endl;
}

void MatOp6() {
	float data[] = { 1,1,2,3 };
	Mat mat1(2, 2, CV_32FC1, data);
	cout << "mat1:/n" << mat1 << endl;

	//행렬의 역행렬
	//inverse of a square matrix 
	Mat mat2 = mat1.inv();
	cout << "mat2:/n" << mat2 << endl;

	cout << "mat1.t():/n" << mat1.t() << endl;
	cout << "mat1 + 3:/n" << mat1 + 3 << endl;
	cout << "mat1+ mat2:/n" << mat1 + mat2 << endl;
	cout << "mat1 + mat2:/n" << mat1 * mat2 << endl;

	//professor
	cout << "mat1 + Scalar(3):/n" << mat1 + Scalar(3) << endl;
	cout << "mat1 + 3:/n" << mat1 * 3 << endl;
	cout << "mat1 / mat2:/n" << mat1 / mat2 << endl;
	cout << "4/ mat1:/n" << 4 / mat1 << endl;
	cout << "mat1.mul(mat2):/n" << mat1.mul(mat2) << endl;

	float data2[] = { 1,2,3,4,5,6 };
	Mat mat3(2, 3, CV_32FC1, data2);
	cout << "mat3:/n" << mat3 << endl;
	cout << "mat3(pseudoinverse by SVD):" << mat3.inv(DECOMP_SVD) << endl;
	cout << "pseudoinverse(left inverse)" << endl;
	cout << (((mat3.t()) *mat3).inv()) * (mat3.t()) << endl;
	cout << "pseudoinverse(right inverse)" << endl;
	cout << (mat3.t()) * ((mat3) * (mat3.t())).inv() << endl << endl;

}
void MatOp7() {
	Mat img1 = imread("lenna.bmp", IMREAD_GRAYSCALE);
	
	//실수형으로 convertTo 함수 사용해서 변환하기 
	Mat img1f;
	img1.convertTo(img1f, CV_32FC1);

	//professor 
	Mat img2f;
	img1.convertTo(img2f, CV_32FC1, 1, 0 / 255);
	imshow("img1", img1);
	imshow("img1f", img1f);
	imshow("img2f", img2f);
	waitKey();

	uchar data1[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	Mat mat1(3, 4, CV_8UC1, data1);
	Mat mat2 = mat1.reshape(0, 1); 

	cout << "mat1:/n" << mat1 << endl;
	cout << "mat2:/n" << mat2 << endl;

	//professor
	Mat mat2_1 = mat1.reshape(3, 2); // 3channels, 2 rows
	cout << "mat2_1:/n" << mat2_1 << endl;
	cout << "mat2_1(channels): " << mat2_1.channels() << endl;
	cout << "mat2_1(size): " << mat2_1.size() << endl;
 
	mat1.resize(5, 100);
	cout << "mat1:/n" << mat1 << endl;

	Mat mat3 = Mat::ones(1, 4, CV_8UC1) * 255;
	mat1.push_back(mat3);
	cout << "mat1:/n" << mat1 << endl;

	//professor
	Mat mat3_1 = Mat::ones(3, 4, CV_8UC1) * 128;
	mat1.push_back(mat3_1);
	cout << "mat1:/n" << mat1 << endl;

	//professor
	Mat mat4(12, 1, CV_8UC1, data1);
	cout << "mat4:/n" << mat4 << endl;
	vector<uchar> mat3_2(2, 50); // 세로로 50 2개 뒤에 붙이기 1행에 
	mat4.push_back(mat3_2);
	cout << "mat4:/n" << mat4 << endl;
	mat4.pop_back(3); // 아래에서 3개 빼라 
	cout << "mat4:/n" << mat4 << endl;

	destroyAllWindows();


}
void ScalarOp() {
	Scalar gray = 128;
	cout << "gray: " << gray << endl;

	//professor
	Scalar gray2(100);
	cout << "gray2: " << gray2 << endl;

	Scalar yellow(0, 255, 255);
	cout << "yellow: " << yellow << endl;

	//professor
	Scalar yellow2 = { 128,128,128,0 };
	cout << "yellow2: " << yellow2 << endl;

	Mat img1(256, 256, CV_8UC3, yellow);

	for (int i = 0; i < 4; i++) {
		cout << yellow[i] << endl;
	}

	imshow("img1", img1);
	waitKey();
}
void VecOp() {
	Vec3b p1, p2(0, 0, 255);
	p1[0] = 100;

	//professor
	p1.val[1] = 150;

	cout << "p1:" << p1 << endl;
	cout << "p2: " << p2 << endl << endl;
}

void InputArrayOp() {
	uchar data1[] = { 1,2,3,4,5,6, };
	Mat mat1(2, 3, CV_8U, data1);
	printMat(mat1);

	vector<float> vec1 = { 1.2f,3.4f,-2.1f };
	printMat(vec1);
}
void printMat(InputArray _mat) {
	Mat mat = _mat.getMat();
	cout << mat << endl;
}

void camera_in() {

	VideoCapture cap("stopwatch.avi");

	if (!cap.isOpened()) {
		cerr << "Camera open failed" << endl;
		return;
	}
	cout << "Frame width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
	cout << "Frame height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
	cout << "Frame count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

	double fps = cap.get(CAP_PROP_FPS);
	cout << "FPS: " << fps << endl;

	int delay = cvRound(1000 / fps);


	Mat frame, inversed;

	while (true) {
		cap >> frame;
		if (frame.empty())
			break;

		inversed = ~frame;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(10) == 27)
			break;
	}
	destroyAllWindows();

}

void camer_in_video_out() {
	VideoCapture cap(0);

	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return;
	}

	int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
	int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
	double fps = cap.get(CAP_PROP_FPS);

	int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
	int delay = cvRound(1000 / fps);

	VideoWriter outputVideo("stopwatch.avi", fourcc, fps, Size(w, h));

	if (!outputVideo.isOpened()) {
		cout << "File open failed! " << endl;
		return;
	}
	Mat frame, inversed;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;
		inversed = ~frame;
		outputVideo << inversed;

		imshow("frame", frame);
		imshow("inversed", inversed);

		if (waitKey(delay) == 27)
			break;

	}
	destroyAllWindows();

}

void drawLines() {
	Mat img(400, 400, CV_8UC3, Scalar(255, 255, 255));

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(200,100), Scalar(0, 0, 255),3);
	line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0),10);

	line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
	line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
	line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

	arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
	arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
	arrowedLine(img, Point(50, 300), Point(350,300), Scalar(255, 0, 0), 1,LINE_8,0,0.5);

	drawMaker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
	drawMaker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
	drawMaker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
	drawMaker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
	drawMaker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
	drawMaker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
	drawMaker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

	imshow("img", img);
	waitKey();
	destroyAllWindows();
}