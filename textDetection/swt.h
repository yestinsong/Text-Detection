#ifndef _SWT_H_
#define _SWT_H_

#include "swtUtil.h"
#include "Candidate.h"
#include <iostream>
#include <vector>
#include <set>
#include "headline.h"
using namespace std;
using namespace cv;



class Swt{
public:
	Swt();
	void initialize(Mat& image,vector< vector<cv::Point2i> >& cc);
	void getStrokeWidth(vector<cv::Point2i>& component, Candidate& cad);
	void gradient();
	void inversegradient();
	void Edges(vector< vector<cv::Point2i> >& cc);
	void td_findPairLine();
	void displayStrokeWidth(vector< vector<cv::Point2i> >& cc);

private:
	cv::Mat StrokeImage;
	cv::Mat GrayImage;
	cv::Mat EdgeImage;
	cv::Mat max_x;
	cv::Mat max_y;
	int height;
	int width;
	Qqueue* qbtc;
	Qqueue* qb; ///for rgb
};

#endif
