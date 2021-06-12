#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std; 

//Mat클래스 
void MatOp5();
void MatOp6();




int main(void) {

	Point pt1;
	pt1.x = 5;
	pt1.y = 10;
	Point pt2(10, 30);
	Point pt3 = pt1 + pt2;
	Point pt4 = pt1 * 2;
	int d1 = pt1.dot(pt2);
	bool b1 = (pt1 == pt2);
	cout << "pt1: " << pt1 << endl;
	cout << "pt2: " << pt2 << endl;
	//내적 확인 
	cout << "dot product: " << d1 << endl;
	//외적 확인 
	cout << "cross product: " << pt1.cross(pt2) << endl;

	Size sz1, sz2(10, 20);
	sz1.width = 5;
	sz1.height = 10;
	Size sz3 = sz1 + sz2;
	Size sz4 = sz1 * 2;
	int area1 = sz4.area();

	cout << "sz3: " << sz3 << endl;
	cout << "sz4: " << sz4 << endl;
	cout << "area(sz4): " << area1 << endl;

	Rect rc1;
	Rect rc2(10, 10, 60, 40);

	Rect rc3 = rc1 + Size(50, 40);
	Rect rc4 = rc2 + Point(10, 10);

	Rect rc5 = rc3 & rc4;
	Rect rc6 = rc3 | rc4;

	cout << "rc5: " << rc5 << endl;
	cout << "rc6: " << rc6 << endl;
	cout << "rc3: " << rc3 << endl;
	cout << "rc4: " << rc4 << endl;

	RotatedRect rr1(Point2f(40, 30), Size2f(40, 20), 30.f);

	Point2f pts[4];
	rr1.points(pts);

	Rect br = rr1.boundingRect();

	for (int i = 0; i < 4; i++) {
		cout << "pts[" << i << "]:" << pts[i] << endl;
	}
	cout << "br:" << br << endl;
	Rect2f br_f = rr1.boundingRect2f();
	cout << "br_f: " << br_f << endl << endl;

	MatOp5(); 
	MatOp6();
	
	return 0;

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
