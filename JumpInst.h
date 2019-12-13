#pragma once
#include"instruction.h"
#include<iostream>
class JumpInst :public instruction {
	//jump a1, a1 is an address
public:
	JumpInst(int);
	virtual int execute();
	~JumpInst();
private:
	int address;
};
JumpInst::JumpInst(int addr):address(addr){}
int JumpInst::execute() {
	return address;
}
JumpInst::~JumpInst(){}
