#include"PolyGroundTruth.h"
using namespace std;


PolyGroundTruth::PolyGroundTruth(std::string s,double xupdate,double yupdate)
{
	vector<cv::Point> vex;
	vector<std::string> ret = Tools::split(s," ");
    cv::Point pt = cv::Point(atoi(ret[0].c_str())*xupdate,atoi(ret[1].c_str())*yupdate);
	vex.push_back(pt);
    cv::Point pt1 = cv::Point(atoi(ret[2].c_str())*xupdate,atoi(ret[3].c_str())*yupdate);
	vex.push_back(pt1);
	rr =cv::boundingRect(vex);
}

PolyGroundTruth::PolyGroundTruth(const cv::Rect& r)
{
	this->rr = r;
}

void PolyGroundTruthSet::display(cv::Mat& image)
{

	cv::Scalar s = cv::Scalar();s[0] = 0; s[1] = 0; s[2] = 255;
	for(int i = 0; i< this->sets.size();i++)
	{
		cv::Rect rec = sets[i].rr;
		cv::rectangle(image,rec, s,3,8,0);
	}
}