#ifndef _CANDIDATE_
#define _CANDIDATE_

///Singal Character detected by GetCandidate 
class Candidate
{
public:
	int max_i,max_j,min_i,min_j;
	double middle_i,middle_j;
	double strokeWidh,strokeVariance;
	double pointsNum;
	double avergecolor,averarer,averareg,averareb;
	double colorVariance;
	double strokeWidthRatio;
	double high;
	double width;
	double highWidthRatio;
	double grayRatio;
	int index;
	int chuan;
	int alive;
};

#endif