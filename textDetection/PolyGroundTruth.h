#ifndef _POLYGROUNDTRUTH_
#define _POLYGROUNDTRUTH_
#include <string>
#include "headline.h"
#include <fstream>
#include <vector>
#include "Tools.h"
class PolyGroundTruth{
public:
	PolyGroundTruth(){}
	PolyGroundTruth(std::string s,double xratio, double yratio);
	PolyGroundTruth(const cv::Rect& r);
private:
	cv::Rect rr;
	friend class PolyGroundTruthSet;
	friend class VericaficationTextLine;
	friend class Fmeasure;
};

class PolyGroundTruthSet{
public:
	void display(cv::Mat& image);
	void push_back(PolyGroundTruth& pgt){sets.push_back(pgt);}
	void clear(){sets.clear();}
private:
	std::vector<PolyGroundTruth>	sets;
	friend class VericaficationTextLine;
	friend class Fmeasure;
};


#endif