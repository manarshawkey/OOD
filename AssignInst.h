#pragma once
#include"instruction.h"
#include<iostream>
//#include"globals.h"
//assign in1, out
class AssignInst : public instruction {
public:
	AssignInst(int, int, bool);
	virtual int execute();
	~AssignInst();
private:
	int in, out;
	bool flag;
};
AssignInst::AssignInst(int op1, int op2, bool flg)
	: flag(flg), in(op1), out((op2 <= 0 || op2 > 1023) ? throw std::invalid_argument("Invalid mem address\n") : op2) {}
int AssignInst::execute() {
	if (flag) {
		in = mem[in];
	}
	mem[out] = in;
	return 0;
}
AssignInst::~AssignInst(){}
