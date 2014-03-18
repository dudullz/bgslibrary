/*
This file is part of BGSLibrary.

BGSLibrary is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

BGSLibrary is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with BGSLibrary.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <vector>
#include "boost/filesystem.hpp"

#include "Config.h"
#include "IFrameProcessor.h"

namespace bgslibrary
{
  class VideoCapture
  {
  private:
    IFrameProcessor* frameProcessor;
    CvCapture* capture;
    IplImage* frame;
    int key;
    int64 start_time;
    int64 delta_time;
    double freq;
    double fps;
    long frameNumber; // this is not frame number!!! it's the index number for std::vector imgNames
    long stopAt;
    bool useCamera;
    int cameraIndex;
    bool useVideo;
    std::string videoFileName;
    int input_resize_percent;
    bool showOutput;
    bool enableFlip;

	bool useImages;
	std::string imgPath;
  std::vector<std::string> imgFiles;
	typedef std::vector<boost::filesystem::path> vec;             // store paths,
	vec imgNames;                                // so we can sort them later
	
  public:
    VideoCapture();
    ~VideoCapture();

    void setFrameProcessor(IFrameProcessor* frameProcessorPtr);
    void setCamera(int cameraIndex);
    void setVideo(std::string filename);
	void setImages(std::string path);
    void start();

  private:
    void setUpCamera();
    void setUpVideo();
	void setUpImages();

    void saveConfig();
    void loadConfig();
  };
}
