#pragma once
#include"instruction.h"
#include<iostream>
//#include"globals.h"
class Jump0Inst : public instruction {
public:
	//jump0 in1 (addr or const), a1(addr)
public:
	Jump0Inst(int, int);
	virtual int execute();
	~Jump0Inst();
private:
	int in1, a1;
};
Jump0Inst::Jump0Inst(int op1, int op2)
	:in1(op1), a1((op2 <= 0 || op2 > 1023) ? throw std::invalid_argument("invalid mem location\n") : op2) {}
int Jump0Inst::execute() {
	if (in1 == 0)
		return a1;
	return 0;
}
Jump0Inst::~Jump0Inst(){}