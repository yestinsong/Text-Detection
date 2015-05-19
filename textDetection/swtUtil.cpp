#include"swtUtil.h"

Qqueue::Qqueue()
{
	str = new Vpoint[3072000];
	for(int i = 0;i<307200;i++)
	{
		str[i].i = 0;
		str[i].j = 0;
		str[i].val = 0;
	}
    inport = 0;
	outport = 0;
	length = inport - outport;
}

Qqueue::~Qqueue()
{
	delete str;
}



void Qqueue::push(Vpoint& m)
{
	str[inport].i = m.i;
	str[inport].j = m.j;
	str[inport].val = m.val;
    inport += 1;
	length = inport - outport;
}

void Qqueue::pop(Vpoint& m)
{
	m.i = str[outport].i;
	m.j = str[outport].j;
	m.val = str[outport].val;
    outport += 1;
	length = inport - outport;
}

void Qqueue:: push_v(Vpoint& m)
{
	str[inport].i = m.i;
	str[inport].j = m.j;
    inport += 1;
	length = inport - outport;
	 
}

void Qqueue::pop_v(Vpoint& m)
{
	m.i = str[outport].i;
	m.j = str[outport].j;
    outport += 1;
	length = inport - outport;
}

void Qqueue::reset()
{
    inport = 0;
	outport = 0;
	length = inport - outport;
}

