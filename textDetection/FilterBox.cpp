#include "FilterBox.h"

bool FilterBox::Keep(cv::Mat& Image)
{
		Rows = cv::Mat::zeros(1,SampleDion,CV_32FC1);
	    	cv::Mat floatImage = cv::Mat( Image.rows,Image.cols,CV_32FC1);
		cv::cvtColor(Image,Image,CV_BGR2GRAY);
		Image.convertTo(floatImage, CV_32F, 1.0/255);
		cv::dct(floatImage,floatImage);
		for(int rowIndex = 0;rowIndex< 60;rowIndex++)
			for(int colIndex = 0; colIndex < 200;colIndex++)
				Rows.at<float>(0,(rowIndex/3)*50 + colIndex/4) += floatImage.at<float>(rowIndex,colIndex);
		cv::Mat m = subspaceProject(pEigVecs, pMean,Rows);
		float labelpre = rtrees.predict_prob(m.row(0));
		return (labelpre > 0.5);
}

FilterBox::FilterBox()
{
	SampleReduceDion = 30;
	SampleDion = 1000;
	rtrees.load("TextLineClassifier");
	pMean = cv::Mat(1,SampleDion,CV_32FC1);
	ifstream fin("pMeanFFT");
	for(int i = 0; i< SampleDion;i++)
		fin>>pMean.at<float>(0,i);
	fin.close();fin.clear();
	fin.open("pEigVecsFFT");
	pEigVecs = cv::Mat(SampleDion,SampleReduceDion,CV_32FC1);
	for(int i = 0; i< SampleDion;i++)
		for(int j = 0;j<SampleReduceDion;j++)
			fin>>pEigVecs.at<float>(i,j);
}
