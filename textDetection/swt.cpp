#include"swt.h"

Swt::Swt()
{
	qbtc = new Qqueue; 
	qb = new Qqueue; 

}

void Swt::initialize(Mat& image,vector< vector<cv::Point2i> >& cc)
{
	image.copyTo(this->GrayImage);
	this->height = GrayImage.rows;
	this->width = GrayImage.cols;
	EdgeImage = cv::Mat::zeros(this->height,this->width,CV_8UC1);
	StrokeImage  = cv::Mat::zeros(this->height,this->width,CV_32FC1);
	Edges(cc);
	StrokeImage  = cv::Mat::zeros(this->height,this->width,CV_32FC1);
//	cv::imshow("Edges", this->EdgeImage);cv::waitKey(10);
	gradient();
	td_findPairLine();
	inversegradient();
	td_findPairLine();
//	displayStrokeWidth(cc);
}

void Swt::gradient()
{
	max_x = cv::Mat::zeros(this->height,this->width,CV_32FC1);
	max_y = cv::Mat::zeros(this->height,this->width,CV_32FC1);
	float temp_y = 0;
	float temp_x = 0;
	float regular = 0;
	for(int i = 1;i<(height - 1);i++)
	{ 
		for(int j = 1;j< (width - 1);j++)
		{
			if(this->EdgeImage.at<unsigned char>(i,j) != 255)
			{continue;}

			temp_y = GrayImage.at<unsigned char>(i,j - 1) - GrayImage.at<unsigned char>(i,j + 1);
			temp_x = GrayImage.at<unsigned char>(i - 1,j) - GrayImage.at<unsigned char>(i + 1,j);
			regular = sqrt(temp_x*temp_x + temp_y*temp_y);
			max_x.at<float>(i,j) = temp_x/regular;
			max_y.at<float>(i,j) = temp_y/regular;
		}
	}
}
void Swt::inversegradient()
{
	for(int i = 1; i< height - 1;i++)
	{
		for(int j = 1; j< width - 1;j++)
		{
			max_x.at<float>(i,j) = -1 * max_x.at<float>(i,j); 
			max_y.at<float>(i,j) = -1 * max_y.at<float>(i,j);
		}
	}
}

void Swt::Edges(vector< vector<cv::Point2i> >& cc)
{
	int ccsize = cc.size();
	for(int i = 0 ;i< ccsize;i++)
	{
		int ccisize = cc[i].size();
		for(int j = 0; j< ccisize;j++)
			StrokeImage.at<float>(cc[i][j].y, cc[i][j].x) = (i + 1);
	}

	for(int i = 1;i < height;i++)
		for(int j = 1; j< width;j++)
			if(StrokeImage.at<float>(i,j) - StrokeImage.at<float>(i,j - 1) != 0)
				this->EdgeImage.at<unsigned char>(i,j) = 255;

	for(int j = 1; j< width;j++)
		for(int i = 1;i < height;i++)
			if(StrokeImage.at<float>(i,j) - StrokeImage.at<float>(i - 1,j) != 0)
				this->EdgeImage.at<unsigned char>(i,j) = 255;
}

void Swt::td_findPairLine()
{
	int nowi,nowj,step_lengh,SPIvaule;
	Vpoint pt;
	for(int i = 1;i< height - 1;i++)
	{ 
		for(int j = 1;j< width - 1;j++)
		{
			if((EdgeImage.at<unsigned char>(i,j) == 255)) 
			{  
				qb->reset();
				step_lengh = 0;
				while( step_lengh < 40 )
				{
					nowi =  int(i + step_lengh*max_x.at<float>(i,j));
					nowj =  int(j + step_lengh*max_y.at<float>(i,j));
					if((nowi < 1)||(nowj < 0)||(nowi >  (height - 1))||(nowj > (width - 1)))
					{break;}

					pt.i = nowi;
					pt.j = nowj;
					qb->push_v(pt);
					if((EdgeImage.at<unsigned char>(nowi,nowj) == 255)&&(nowi != i)&&(nowj != j))
					{
						if((max_x.at<float>(i,j)*max_x.at<float>(nowi,nowj) + max_y.at<float>(i,j)*max_y.at<float>(nowi,nowj)) < - 0.5)
						{
							while(qb->length)
							{
								qb->pop_v(pt); 
								SPIvaule = StrokeImage.at<float>(pt.i,pt.j);
								if(SPIvaule == 0)
								{  StrokeImage.at<float>(pt.i,pt.j) = step_lengh;}
								else
								{
									if(SPIvaule > step_lengh)
									{  StrokeImage.at<float>(pt.i,pt.j) = step_lengh;}
								}
							}
						}
						break;
					}
					step_lengh += 1;	
				}
				qb->reset();
			}
		} 
	}
}

void Swt::displayStrokeWidth(vector< vector<cv::Point2i> >& cc)
{
	cv::Mat show = cv::Mat::zeros(height,width,CV_8UC3);
	cv::Vec3b  point = Vec3b(0,0,0);

	int ccsize = cc.size();
	for(int i = 0 ;i< ccsize;i++)
	{
		int ccisize = cc[i].size();
		for(int j = 0; j< ccisize;j++)
		{
			int iindex = cc[i][j].y,jindex = cc[i][j].x;
			if(StrokeImage.at<float>(iindex,jindex) == 151) 
				StrokeImage.at<float>(iindex,jindex) = 0; 
			point[1] = int(StrokeImage.at<float>(iindex,jindex)*5);
			show.at<cv::Vec3b>(iindex,jindex) = point;
		}
	}
	cv::imshow(" inner Stroke width",show);
	cv::waitKey(10);
}

void Swt::getStrokeWidth(vector<cv::Point2i>& component, Candidate& cad)
{
	double ccisize = component.size();
	double NumWidth = 0, avgstrokewidth = 0, variancestrokewidth = 0; 
	for(int i = 0; i< ccisize;i++)
	{
		int iindex = component[i].y,jindex = component[i].x;
		if(StrokeImage.at<float>(iindex,jindex) == 151 || StrokeImage.at<float>(iindex,jindex) == 0) 
			StrokeImage.at<float>(iindex,jindex) = 0; 
		else
			NumWidth++;
		avgstrokewidth += StrokeImage.at<float>(iindex,jindex);
		variancestrokewidth += (StrokeImage.at<float>(iindex,jindex) * StrokeImage.at<float>(iindex,jindex));
	}
	cad.strokeWidthRatio = NumWidth/ccisize;
	cad.strokeWidh = avgstrokewidth/ccisize;
	cad.strokeVariance = (variancestrokewidth/ccisize) - (cad.strokeWidthRatio)*(cad.strokeWidthRatio);
}
