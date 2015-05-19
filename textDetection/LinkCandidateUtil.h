#ifndef MY_QUENE_H
#define MY_QUENE_H

#include <iostream>
using namespace std;


class Iqueue
{
public:
	Iqueue();
	~Iqueue();

	int pop();
	void push(int n);
	void reset();

	int length;
	int inport;
	int outport;
	int *str;
};

#endif