# HistogramEqualization16Bit
Histogram equalization on 16 bit images. (As of 9th February 2019) While OpenCV can perform [histogram equalization](https://docs.opencv.org/master/d4/d1b/tutorial_histogram_equalization.html), it only works on 8 bit images.

This project shows how to perform histogram equalization directly on 16 bit images (without downsampling to 8 bit).

## Description

This project will read 16 bit grayscale image(HistogramEqualization\Image\16bit_grayscale.TIF), perform histogram equalization and save the output in "HistogramEqualization\Output\16bit_grayscale.TIF".

Please find the histogram equalization method in Histogram\Histogram.cpp. It is based on similar OpenCV method [equalizeHist()](https://github.com/opencv/opencv/blob/master/modules/imgproc/src/histogram.cpp).

### Prerequisites

This project uses [CMAKE](https://cmake.org/).
This project requires you to have precompiled [OpenCV](https://opencv.org/) library.

### Installing

1. Clone this project

1. Edit CMakeLists.txt at the root folder of this project to set the correct OpenCV path.

    ```
    # Make sure to configure this block
    ###############################################################################
    set(OpenCV_DIR "D:/Project/DurrNDT/opencv")
    # we want to copy OpenCV bin files to build dir
    set(OpenCV_BIN_DIR "D:/Project/DurrNDT/opencv/x64/vc15/bin") 
    ###############################################################################
    ```

1. If you are not using OpenCV 4.0.1, make appropriate changes in the same CMakeLists.txt

    ```
    find_package(OpenCV 4.0.1 REQUIRED)
    ```

1. Configure and generate using cmake/cmake-gui

    ![CMAKE-GUI](https://i.imgur.com/YFGrCRv.png)

1. Find generated .sln and compile with Visual Studio. 

1. Execute HistogramEqualization.exe and check the output image in "Output\16bit_grayscale.TIF"

## Running the tests

Histogram-Test is the testing project. It uses [googletest](https://github.com/google/googletest) framework.

## Potential improvement

Speed of the method can be improve (potentially) by
* parallel processing
* uses OpenCL
* uses OpenVX

I uses platform specific function in the main function. This can be improved by using C++17(among others).

Histogram equalization method depends on OpenCV.

## Built With

* [OpenCV](https://opencv.org/) 
* [googletest](https://github.com/google/googletest) 
* [cmake](https://cmake.org/)

## Authors

* **[Syaiful Nizam Yahya](https://syaifulnizamyahya.wordpress.com/)**

## Acknowledgments

* Nick D'Ademo
