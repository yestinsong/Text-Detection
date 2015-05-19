#ifndef  _TOOLS_H_
#define _TOOLS_H_
#include <string>
#include <vector>

class Tools{
public:
	static std::vector<std::string> split(std::string str,std::string pattern);
	static double min(double a1, double a2){double ret = (a1 < a2)?a1:a2; return ret;}
	static double max(double a1, double a2){double ret = (a1 > a2)?a1:a2; return ret;}
};


#endif