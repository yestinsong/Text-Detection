#include"LinkCandidateUtil.h"

Iqueue::Iqueue()
{
	length = 0;
	inport = 0;
	outport = 0;
	str = new int[3000];
}

Iqueue::~Iqueue()
{

}

int Iqueue::pop()
{
    outport += 1;
	length = inport - outport;
	return str[outport - 1];
}

void Iqueue::push(int n)
{
	str[inport] = n;
    inport += 1;
	length = inport - outport;
}

void Iqueue::reset()
{
 	length = 0;
	inport = 0;
	outport = 0;
}


