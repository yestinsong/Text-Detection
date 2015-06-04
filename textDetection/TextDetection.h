#ifndef _TEXT_DETECTION_
#define _TEXT_DETECTION_

#include "headline.h"
#include <iostream>
#include <vector>
#include <string>
#include "GroundDetect.h"

class TextDetection{
public:
	std::string detectText(const cv::Mat& image,const std::vector<std::string> gt = std::vector<std::string>(),bool isshow = true);
private:
	GroundDetect gd;

};


#endif 
