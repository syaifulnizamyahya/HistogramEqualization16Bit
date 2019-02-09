#include "Histogram.h"

void Histogram::equalizeHistogram(const cv::Mat &_src, cv::Mat &_dst)
{
	if (_src.empty())
		return;

	auto type = _src.type();
	if (type == 0)
	{
		equalizeHist8Bit(_src, _dst);
		//cv::equalizeHist(_src, _dst);
	}
	else if (type == 2)
	{
		equalizeHist16Bit(_src, _dst);
	}
	else
	{
		return;
	}
}

void Histogram::equalizeHist8Bit(const cv::Mat &_src, cv::Mat &_dst)
{
	_dst = _src.clone();

	const int hist_sz = 256;
	int *hist = new int[hist_sz] {};
	int *lut = new int[hist_sz] {};

	for (int y = 0; y < _src.rows; y++)
		for (int x = 0; x < _src.cols; x++)
			hist[(int)_src.at<unsigned char>(y, x)]++;

	auto i = 0;
	while (!hist[i]) ++i;

	auto total = (int)_src.total();
	if (hist[i] == total)
	{
		_dst.setTo(i);
		return;
	}

	float scale = (hist_sz - 1.f) / (total - hist[i]);
	auto sum = 0;

	for (lut[i++] = 0; i < hist_sz; ++i)
	{
		sum += hist[i];
		lut[i] = cv::saturate_cast<unsigned char>(sum * scale);
	}

	for (int y = 0; y < _src.rows; y++)
		for (int x = 0; x < _src.cols; x++)
		{
			_dst.at<unsigned char>(y, x) = lut[(int)_src.at<unsigned char>(y, x)];
		}
}

void Histogram::equalizeHist16Bit(const cv::Mat &_src, cv::Mat &_dst)
{
	_dst = _src.clone();

	const int hist_sz = 65536;
	int *hist = new int[hist_sz] {};
	int *lut = new int[hist_sz] {};

	for (int y = 0; y < _src.rows; y++)
		for (int x = 0; x < _src.cols; x++)
			hist[(int)_src.at<unsigned short int>(y, x)]++;

	auto i = 0;
	while (!hist[i]) ++i;

	auto total = (int)_src.total();
	if (hist[i] == total) 
	{
		_dst.setTo(i);
		return;
	}

	float scale = (hist_sz - 1.f) / (total - hist[i]);
	auto sum = 0;

	for (lut[i++] = 0; i < hist_sz; ++i) 
	{
		sum += hist[i];
		lut[i] = cv::saturate_cast<ushort>(sum * scale);
	}

	for (int y = 0; y < _src.rows; y++)
		for (int x = 0; x < _src.cols; x++)
		{
			_dst.at<unsigned short int>(y, x) = lut[(int)_src.at<unsigned short int>(y, x)];
		}
}
