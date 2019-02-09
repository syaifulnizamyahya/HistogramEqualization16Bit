// HistogramEqualization.cpp : Defines the entry point for the application.
//

#include "HistogramEqualization.h"

using namespace cv;
using namespace std;

void Task()
{
	// read 16 bit image
	string imageName = "16bit_grayscale.TIF";
	string inputPath = "Image\\";
	string inputFilename = inputPath + imageName;
	cout << "Reading image : " << inputFilename << endl;
	Mat image = imread(inputFilename, IMREAD_ANYDEPTH);
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		return;
	}

	// perform histogram equalization
	Mat resultImage;
	cout << "Histogram equalization." << endl;
	Histogram::equalizeHistogram(image, resultImage);

	// save resulting equalize image as a 16 bit image
	string outputPath = "Output\\";
	string outputFileName = outputPath + imageName;
	//filesystem::create_directory(outputPath);
	if (CreateDirectory(outputPath.c_str(), NULL) ||
		ERROR_ALREADY_EXISTS == GetLastError())
	//if exist, delete
	if (remove(outputFileName.c_str()) != 0)
		cout << "Error deleting " << outputFileName << endl;
	cout << "Writing image : " << outputFileName << endl;
	try {
		imwrite(outputFileName, resultImage);
	}
	catch (cv::Exception& ex) {
		cout << "Exception converting image : " << ex.what();
		return;
	}
	cout << "Done histogram equalization!" << endl;
}

int main(int argc, char** argv)
{
	Task();

	cout << "Press ENTER to quit" << endl;
	cin.get();

	return 0;
}
