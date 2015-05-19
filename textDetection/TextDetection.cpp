#include"TextDetection.h"

std::string TextDetection::detectText(const cv::Mat& image,const std::vector<std::string> gt,bool isshow)
{
	gd.readImageGroundTruth(image,gt);
	gd.run();
	if(isshow == true)
		gd.showPolyGroundTruthSet();
	if(gt.size() == 0)
		return "";
	else
		return gd.calculateResult();
}