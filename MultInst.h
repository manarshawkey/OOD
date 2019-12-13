#pragma once
#include"instruction.h"
#include<iostream>
//#include"globals.h"
//mul in1, in2, out
class MultInst : public instruction {
public:
	MultInst(int, int, int, bool, bool);
	virtual int execute();
	~MultInst();
private:
	int in1, in2, out;
	bool flag1, flag2;
};
MultInst::MultInst(int op1, int op2, int op3, bool flg1, bool flg2) : flag1(flg1), flag2(flg2), in1(op1), in2(op2),
out((op3 <= 0 || op3 > 1023) ? throw std::invalid_argument("Invalid mem location\n") : op3) {}
int MultInst::execute() {
	if (flag1) in1 = mem[in1];
	if (flag2) in2 = mem[in2];
	mem[out] = in1 * in2;
	return 0;
}
MultInst::~MultInst(){}
