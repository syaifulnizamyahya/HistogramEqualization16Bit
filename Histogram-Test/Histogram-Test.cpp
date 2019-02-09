#include "../Histogram/Histogram.h"
#include "gtest/gtest.h"

TEST(HistogramEqualization, Valid16bitInput) 
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<ushort>(4, 4) <<
		0, 4369, 8738, 13107,
		17476, 21845, 26214, 30583,
		34952, 39321, 43690, 48059, 
		52428, 56797, 61166, 65535
		);

	result = (cv::Mat_<ushort>(4, 4) <<
		0, 4369, 8738, 13107,
		17476, 21845, 26214, 30583,
		34952, 39321, 43690, 48059,
		52428, 56797, 61166, 65535
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "16 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, Valid8bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<uchar>(2, 2) <<
		0, 85, 
		170, 255
		);

	result = (cv::Mat_<uchar>(2, 2) <<
		0, 85,
		170, 255
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "8 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, Zero8bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<uchar>(2, 2) <<
		0, 0,
		0, 0
		);

	result = (cv::Mat_<uchar>(2, 2) <<
		0, 0,
		0, 0
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "Zero 8 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, Zero16bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<ushort>(4, 4) <<
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
		);

	result = (cv::Mat_<ushort>(4, 4) <<
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "Zero 16 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, One8bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<uchar>(2, 2) <<
		1, 1,
		1, 1
		);

	result = (cv::Mat_<uchar>(2, 2) <<
		1, 1,
		1, 1
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "One 8 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, One16bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<ushort>(4, 4) <<
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
		);

	result = (cv::Mat_<ushort>(4, 4) <<
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "One 16 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, Max8bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<uchar>(2, 2) <<
		255, 255,
		255, 255
		);

	result = (cv::Mat_<uchar>(2, 2) <<
		255, 255,
		255, 255
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "Max 8 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}

TEST(HistogramEqualization, Max16bitInput)
{
	cv::Mat src;
	cv::Mat dst;
	cv::Mat result;

	src = (cv::Mat_<ushort>(4, 4) <<
		65535, 65535, 65535, 65535,
		65535, 65535, 65535, 65535,
		65535, 65535, 65535, 65535,
		65535, 65535, 65535, 65535
		);

	result = (cv::Mat_<ushort>(4, 4) <<
		65535, 65535, 65535, 65535,
		65535, 65535, 65535, 65535,
		65535, 65535, 65535, 65535,
		65535, 65535, 65535, 65535
		);

	Histogram::equalizeHistogram(src, dst);
	std::cout << "Max 16 bit" << std::endl;
	std::cout << "Source M :" << std::endl;
	std::cout << src << std::endl << std::endl;
	std::cout << "Destination M :" << std::endl;
	std::cout << dst << std::endl << std::endl;
	std::cout << "Result M :" << std::endl;
	std::cout << result << std::endl << std::endl;
	cv::Mat diff = dst != result;
	EXPECT_TRUE(cv::countNonZero(diff) == 0);
}