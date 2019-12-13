#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
#include"instruction.h"
//#include"globals.h"
class ReadInst : public instruction {
public:
	ReadInst(int);
	virtual int execute();
	~ReadInst();
private:
	int address;
};
ReadInst::ReadInst(int addr)
	:address((addr <= 0 || addr > 1023) ? throw std::invalid_argument("Invalid mem location.\n") : addr) {}
int ReadInst::execute() {
	int value;
	std::cout << "Read executes: please enter a value: ";
	std::cin >> value;
	mem[address] = value;
	return 0;
}
ReadInst::~ReadInst(){}