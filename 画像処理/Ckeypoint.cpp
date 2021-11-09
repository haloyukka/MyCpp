#include "Ckeypoint.h"
#include <iostream>

using namespace cv;
using namespace std;


Ckeypoint::Ckeypoint()
{
}

Ckeypoint::~Ckeypoint()
{
}

/*
FAST 処理
*/
void Ckeypoint::FAST_t(InputArray image, IplImage *src,	vector<KeyPoint>& keypoints, int threshold,	bool nonmax_suppression)
{
	Mat img = image.getMat();
	const int K = 16 / 2;		//周囲16画素の場合は9連続
	const int N = 16 + K + 1;	//周囲16画素の場合は9連続
	int i, j, k, pixel[25];
	makeoffsets(pixel, (int)img.step, 16);

	keypoints.clear();

	threshold = std::min(std::max(threshold, 0), 255);

	uchar threshold_tab[512];
	for (i = -255; i <= 255; i++)
		threshold_tab[i + 255] = (uchar)(i < -threshold ? 1 : i > threshold ? 2 : 0);

	AutoBuffer<uchar> _buf((img.cols + 16) * 3 * (sizeof(int) + sizeof(uchar)) + 128);
	uchar* buf[3];
	buf[0] = _buf; buf[1] = buf[0] + img.cols; buf[2] = buf[1] + img.cols;
	int* cpbuf[3];
	cpbuf[0] = (int*)alignPtr(buf[2] + img.cols, sizeof(int)) + 1;
	cpbuf[1] = cpbuf[0] + img.cols + 1;
	cpbuf[2] = cpbuf[1] + img.cols + 1;
	memset(buf[0], 0, img.cols * 3);

	for (i = 3; i < img.rows - 2; i++){
		const uchar* ptr = img.ptr<uchar>(i) + 3;
		uchar* curr = buf[(i - 3) % 3];
		int* cornerpos = cpbuf[(i - 3) % 3];
		memset(curr, 0, img.cols);
		int ncorners = 0;

		if (i < img.rows - 3)
		{
			j = 3;
			for (; j < img.cols - 3; j++, ptr++){
				int v = ptr[0];
				const uchar* tab = &threshold_tab[0] - v + 255;
				int d = tab[ptr[pixel[0]]] | tab[ptr[pixel[8]]];

				if (d == 0)
					continue;

				d &= tab[ptr[pixel[2]]] | tab[ptr[pixel[10]]];
				d &= tab[ptr[pixel[4]]] | tab[ptr[pixel[12]]];
				d &= tab[ptr[pixel[6]]] | tab[ptr[pixel[14]]];

				if (d == 0)
					continue;

				d &= tab[ptr[pixel[1]]] | tab[ptr[pixel[9]]];
				d &= tab[ptr[pixel[3]]] | tab[ptr[pixel[11]]];
				d &= tab[ptr[pixel[5]]] | tab[ptr[pixel[13]]];
				d &= tab[ptr[pixel[7]]] | tab[ptr[pixel[15]]];

				if (d & 1) //Darker
				{
					int vt = v - threshold, count = 0;

					for (k = 0; k < N; k++){
						int x = ptr[pixel[k]];
						if (x < vt)
						{
							if (++count > K)
							{
								cornerpos[ncorners++] = j;
								if (nonmax_suppression)
									curr[j] = (uchar)cornerScore(ptr, pixel, threshold);
								break;
							}
						}
						else
							count = 0;
					}
				}

				if (d & 2) //Brighter
				{
					int vt = v + threshold, count = 0;

					for (k = 0; k < N; k++){
						int x = ptr[pixel[k]];
						if (x > vt)
						{
							if (++count > K)
							{
								cornerpos[ncorners++] = j;
								if (nonmax_suppression)
									curr[j] = (uchar)cornerScore(ptr, pixel, threshold);
								break;
							}
						}
						else
							count = 0;
					}
				}
			}
		}

		cornerpos[-1] = ncorners;

		if (i == 3)
			continue;

		const uchar* prev = buf[(i - 4 + 3) % 3];
		const uchar* pprev = buf[(i - 5 + 3) % 3];
		cornerpos = cpbuf[(i - 4 + 3) % 3];
		ncorners = cornerpos[-1];

		for (k = 0; k < ncorners; k++){
			j = cornerpos[k];
			int score = prev[j];
			if (!nonmax_suppression ||
				(score > prev[j + 1] && score > prev[j - 1] &&
					score > pprev[j - 1] && score > pprev[j] && score > pprev[j + 1] &&
					score > curr[j - 1] && score > curr[j] && score > curr[j + 1]))
			{
				keypoints.push_back(KeyPoint((float)j, (float)(i - 1), 7.f, -1, (float)score));
			}
		}
	}
}


/*
 offset作成用関数
 offset16は相対座標。横の座標軸の積をとって1次元配列のオフセット値を算出。
 今回は周囲16画素が対象のため、pixel[0] - pixel[15]までに座標値が格納される。
*/
void Ckeypoint::makeoffsets(int pixel[25], int rowStride, int patternSize)
{
	static const int offsets16[][2] =
	{
		{ 0,  3 },{  1,  3 },{  2,  2 },{  3,  1 },{  3, 0 },{  3, -1 },{  2, -2 },{  1, -3 },
		{ 0, -3 },{ -1, -3 },{ -2, -2 },{ -3, -1 },{ -3, 0 },{ -3,  1 },{ -2,  2 },{ -1,  3 }
	};

	int k = 0;
	for (; k < patternSize; k++)
		pixel[k] = offsets16[k][0] + offsets16[k][1] * rowStride;
	for (; k < 25; k++)
		pixel[k] = pixel[k - patternSize];
}

/*
cornerScore作成用関数
*/
int Ckeypoint::cornerScore(const uchar* ptr, const int pixel[], int threshold)
{
	const int K = 8, N = K * 3 + 1;
	int k, v = ptr[0];
	short d[N];
	for (k = 0; k < N; k++)
		d[k] = (short)(v - ptr[pixel[k]]);

	return threshold;
}

