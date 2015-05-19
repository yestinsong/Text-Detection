#ifndef _SWT_UTIL_H_
#define _SWT_UTIL_H_

struct Vpoint{
   int i;
   int j;
   float val;
};

class Qqueue
{
public:
	 Qqueue();
	~Qqueue();

	 void push(Vpoint& m);
	 void pop (Vpoint& m);
	 void push_v(Vpoint& m);
	 void pop_v(Vpoint& m);
	 void reset();

	 int length; 
	 int inport;
	 int outport;
	 Vpoint* str;
	 Vpoint* originalstr;
};


#endif