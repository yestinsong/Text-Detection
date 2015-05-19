#ifndef _FMEASURE_
#define _FMEASURE_
#include<string>
#include<vector>
#include "PolyGroundTruth.h"
#include "headline.h"
class Fmeasure{
public:
	std::string run(PolyGroundTruthSet& cgts,PolyGroundTruthSet& pgts);
	double PrecisionRecall(PolyGroundTruthSet& cgts,PolyGroundTruthSet& pgts);
	double getPrecisionRecall(PolyGroundTruthSet& cgts,PolyGroundTruthSet& pgts);
	double intersection(const cv::Rect& r1,const cv::Rect& r2);
};
#endif