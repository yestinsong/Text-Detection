#include "GroundDetect.h"

void GroundDetect::readImageGroundTruth(const cv::Mat& image,const std::vector<std::string> gt)
{
	pgts.clear();
	cgts.clear();
	candidateStore.clear();
	oriBgrImage_8UC3 = image;
	int xupdate = (oriBgrImage_8UC3.cols < 1280)?oriBgrImage_8UC3.cols:1280;
	int yupdate = (oriBgrImage_8UC3.rows < 960)?oriBgrImage_8UC3.rows:960;
	double xratio = double(xupdate)/oriBgrImage_8UC3.cols;
	double yratio = double(yupdate)/oriBgrImage_8UC3.rows;
	cv::resize(oriBgrImage_8UC3,oriBgrImage_8UC3,cv::Size(xupdate,yupdate));
	for(int i = 0; i< gt.size();i++)
		pgts.push_back(PolyGroundTruth(gt[i],xratio,yratio));
}


void GroundDetect::run()
{
	this->candidateStore = this->getCandidate.run(this->oriBgrImage_8UC3);
	this->cgts = this->linkCandidate.run(this->candidateStore);
	this->cgts = this->vericaficationTextLine.run(this->cgts,this->oriBgrImage_8UC3);
}

std::string GroundDetect::calculateResult()
{
	return this->fmeasure.run(cgts,pgts);
}

void GroundDetect::showPolyGroundTruthSet()
{
	this->cgts.display(oriBgrImage_8UC3);
	cv::imshow("Final Result",oriBgrImage_8UC3);
	cv::waitKey(20);
}
