#pragma once
#include"instruction.h"
#include<iostream>
//#include"globals.h"
//LE in1, in2, out
//out must be an address
class LessEqInst : public instruction {
public:
	LessEqInst(int, int, int, bool, bool);
	virtual int execute();
	~LessEqInst();
private:
	int in1, in2, out;
	bool flag1, flag2;
};
LessEqInst::LessEqInst(int op1, int op2, int op3, bool flg1, bool flg2)
	: flag1(flg1), flag2(flg2), in1(op1), in2(op2), out((op3 <= 0 || op3 > 1023) ? throw std::invalid_argument("Invalid mem location\n") : op3) {}
int LessEqInst::execute() {
	if (flag1) in1 = mem[in1];
	if (flag2) in2 = mem[in2];
	if (in1 <= in2)
		mem[out] = 1;
	else
		mem[out] = 0;
	return 0;
}
LessEqInst::~LessEqInst(){}
