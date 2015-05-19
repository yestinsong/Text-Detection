#include"VericaficationTextLine.h"
using namespace std;
using namespace cv;

PolyGroundTruthSet VericaficationTextLine::run(PolyGroundTruthSet& cgts,cv::Mat& rgb)
{
	this->cgts = cgts;
	this->clearInnerBox();
	this->FilterBoxWithPCAandRandomForest(rgb);
	return cgts;

}

 void VericaficationTextLine::FilterBoxWithPCAandRandomForest(cv::Mat& rgb)
 {
	vector<PolyGroundTruth> newset;
	vector<PolyGroundTruth>& sets = this->cgts.sets; 
	for(int i = 0; i< sets.size();i++)
	{
		cv::Mat rgb_copy = rgb;cv::Mat cropped;
		double midx = sets[i].rr.x + sets[i].rr.width/2;
		double midy = sets[i].rr.y + sets[i].rr.height/2;
		getRectSubPix(rgb_copy, sets[i].rr.size(),cv::Point2f(midx,midy),cropped,-1);
		cv::resize(cropped,cropped,Size(200,60));
		if(fb.Keep(cropped)) newset.push_back(PolyGroundTruth(sets[i].rr));
	}
	sets = newset;
 }

 void VericaficationTextLine::clearInnerBox()
{
	vector<PolyGroundTruth>& sets = this->cgts.sets; 
	vector<int> sign(sets.size(),1);
	for(int i = 0 ;i< sets.size();i++)
	{
		for(int j = 0;j < sets.size();j++)
		{
			if(i == j) continue;
			if(sets[i].rr.area() > sets[j].rr.area()) continue;

			cv::Rect rec = sets[i].rr & sets[j].rr;
			double theriod = double(sets[i].rr.area()) * 0.9;
			if(rec.area() > theriod) 
			{	sign[i] = 0; break;}
		}
	}
	
	vector<PolyGroundTruth> repalce;
	for(int i = 0; i< sets.size();i++)
		if(sign[i] != 0) repalce.push_back(sets[i]);
	sets = repalce;
}