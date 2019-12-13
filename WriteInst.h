#pragma once
#include"instruction.h"
#include<iostream>	
//#include"globals.h"
//Write addr: print the value of x in the console
class WriteInst: public instruction{
public:
	WriteInst(int, bool);
	virtual int execute();
	~WriteInst();
private:
	int value;
	bool flg;
};
WriteInst::WriteInst(int val, bool flg) :value(val), flg(flg) {}
	//:address((addr <= 0 || addr > 1023)? throw std::invalid_argument("Invalid mem address\n") : addr){}
int WriteInst::execute() {
	if (flg) std::cout << mem[value] << std::endl;
	else
	std::cout << value << std::endl;
	return 0;
}
WriteInst::~WriteInst(){}