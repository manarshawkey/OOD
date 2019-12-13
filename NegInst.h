#pragma once
#include"instruction.h"
#include<iostream>
//#include"globals.h"
class NegInst : public instruction {
public: 
	NegInst(int, int, bool);
	virtual int execute();
	~NegInst();
private:
	int in, out;
	bool flag;
};
NegInst::NegInst(int op1, int op2, bool flg)
	: flag(flg), in(op1), out((op2 <= 0 || op2 > 1023)?throw std::invalid_argument("Invalid mem address\n"):op2){}
int NegInst::execute() {
	if (flag) {
		in = mem[in];
	}
	mem[out] = -1 * in;
	return 0;
}
NegInst::~NegInst(){}

