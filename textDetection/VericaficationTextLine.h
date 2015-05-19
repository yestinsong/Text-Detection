#ifndef _VERICAFICATION_TEXT_LINE_
#define _VERICAFICATION_TEXT_LINE_
#include "headline.h"
#include "PolyGroundTruth.h"
#include "FilterBox.h"


class VericaficationTextLine{
public:
	PolyGroundTruthSet run(PolyGroundTruthSet& cgts,cv::Mat& rgb);
	void FilterBoxWithPCAandRandomForest(cv::Mat& rgb);
	void clearInnerBox();
private:
	PolyGroundTruthSet cgts;
	FilterBox fb;
	
};

#endif