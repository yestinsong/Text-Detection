#ifndef _FILTER_BOX_H_
#define _FILTER_BOX_H_
#include<string>
#include<vector>
#include "headline.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;

///class used by recognize the non-text text line
class FilterBox{
public:
	FilterBox();
	bool Keep(cv::Mat& ima);
private:
	cv::Mat pMean;
	cv::Mat pEigVecs;
	int SampleReduceDion;
	CvRTrees rtrees;
	int SampleDion;
	cv::Mat Rows;
};


#endif