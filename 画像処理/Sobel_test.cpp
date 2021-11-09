//**********************************************************
// sobel filter simulate
// 2017.09.20
//**********************************************************
#include <opencv2/opencv.hpp>				//OpenCV header
#pragma comment(lib,"opencv_world330.lib")	// OpenCV library release
#pragma comment(lib,"opencv_world330d.lib")	// OpenCV library debug
//
//using namespace std;
//using namespace cv;
//
//int main(int argc, char* argv[])
//{
//	if (argc < 2) {
//		std::cerr << "no parameter." << std::endl;
//		return -1;
//	}
//	
//	IplImage *src = cvLoadImage(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
//
//
//
//
//
//	cvReleaseImage(&src);
//	cv::waitKey(0);
//
//	return 0;
//
//}

//**********************************************************
// matching test
// 2017.09.27
//**********************************************************
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
//#include"OpenCV3.h" //OpenCV�ǂݍ��ݎ���w�b�_

using namespace std;
using namespace cv;

int main(void)
{
	Mat Src1 = imread("C:\\color\\test0.bmp");
	Mat Src2 = imread("C:\\color\\test1.bmp");

	//�L�[�|�C���g���o�Ɠ����ʋL�q
	vector<KeyPoint> keypoints1;
	vector<KeyPoint> keypoints2;
	Mat descriptors1, descriptors2;
	cv::Ptr<cv::AKAZE> akaze = cv::AKAZE::create();
	akaze->detectAndCompute(Src1, cv::Mat(), keypoints1, descriptors1);
	akaze->detectAndCompute(Src2, cv::Mat(), keypoints2, descriptors2);

	//�}�b�`���O(knn�}�b�`���O)
	vector<vector<cv::DMatch>> knnmatch_points;
	cv::BFMatcher match(cv::NORM_HAMMING);
	match.knnMatch(descriptors1, descriptors2, knnmatch_points, 2);

	//�Ή��_���i��
	const double match_par = 0.6; //���_���c���ꍇ�̂������l
	vector<cv::DMatch> goodMatch;
	//KeyPoint -> Point2d
	vector<cv::Point2f> match_point1;
	vector<cv::Point2f> match_point2;
	for (size_t i = 0; i < knnmatch_points.size(); ++i) {
		double distance1 = knnmatch_points[i][0].distance;
		double distance2 = knnmatch_points[i][1].distance;

		//�����_���狗���l������Ă���_�̂ݒ��o�i�����_�����c���j
		if (distance1 <= distance2 * match_par) {
			goodMatch.push_back(knnmatch_points[i][0]);
			match_point1.push_back(keypoints1[knnmatch_points[i][0].queryIdx].pt);
			match_point2.push_back(keypoints2[knnmatch_points[i][0].trainIdx].pt);
		}
	}

	//�z���O���t�B�s�񐄒�
	cv::Mat masks;
	cv::Mat H = cv::findHomography(match_point1, match_point2, masks, cv::RANSAC, 3);

	//RANSAC�Ŏg��ꂽ�Ή��_�̂ݒ��o
	vector<cv::DMatch> inlinerMatch;
	for (size_t i = 0; i < masks.rows; ++i) {
		uchar *inliner = masks.ptr<uchar>(i);
		if (inliner[0] == 1) {
			inlinerMatch.push_back(goodMatch[i]);
		}
	}

	//�Ή��_�̕\��
	cv::Mat drawmatch;
	cv::drawMatches(Src1, keypoints1, Src2, keypoints2, goodMatch, drawmatch);
	imwrite("match_point.jpg", drawmatch);

	//�C�����C�A�̑Ή��_�̂ݕ\��
	cv::Mat drawMatch_inliner;
	cv::drawMatches(Src1, keypoints1, Src2, keypoints2, inlinerMatch, drawMatch_inliner);
	imwrite("match_inliner.jpg", drawMatch_inliner);

	imshow("DrawMatch", drawmatch);
	imshow("Inliner", drawMatch_inliner);
	waitKey();

	return 0;
}
