#ifndef _GROUND_DETECT_
#define _GROUND_DETECT_
#include<string>
#include"Candidate.h"
#include"PolyGroundTruth.h"
#include"GetCandidate.h"
#include"LinkCandidate.h"
#include"VericaficationTextLine.h"
#include"Fmeasure.h"
#include "headline.h"

class GroundDetect{
public:
	void readImageGroundTruth(const cv::Mat& image,const std::vector<std::string> gt);
	void run();
	void showPolyGroundTruthSet();
	std::string calculateResult();
private:
	GetCandidate getCandidate;
	LinkCandidate linkCandidate;
	VericaficationTextLine vericaficationTextLine;
	Fmeasure fmeasure;

	cv::Mat oriBgrImage_8UC3;
	std::vector<Candidate> candidateStore;
	PolyGroundTruthSet cgts;
	PolyGroundTruthSet pgts;
	std::string PRF;///precision,recall,F-measure
};

#endif