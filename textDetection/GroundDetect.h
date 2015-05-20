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
///Main class for text detection
class GroundDetect{
public:
	void readImageGroundTruth(const cv::Mat& image,const std::vector<std::string> gt);
	void run();
	void showPolyGroundTruthSet();
	std::string calculateResult();
private:
	GetCandidate getCandidate;///class for get all characters from input image
	LinkCandidate linkCandidate;///class for link characters into text lines
	VericaficationTextLine vericaficationTextLine;///class for text line vericafication
	Fmeasure fmeasure;//class for calculating the F-measure based on cgts and pgts

	cv::Mat oriBgrImage_8UC3;///Copy of the input Image
	std::vector<Candidate> candidateStore;///Character set calculated by the system
	PolyGroundTruthSet cgts;///The Rect region calculdated by the system
	PolyGroundTruthSet pgts;///The Rect region transform by gt
	std::string PRF;///precision,recall,F-measure
};

#endif
