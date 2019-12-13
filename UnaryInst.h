#pragma once
#include"instruction.h"
#include<string>
#include<iostream>
//int mem[1024];
class UnaryInst :public instruction {
public:
	UnaryInst(std::string, int, int);
	virtual int execute();
private:
	int oprnd1;
	std::string type;
};
UnaryInst::UnaryInst(std::string type, int oprnd1, int des) :
	instruction(des),
	oprnd1(oprnd1), type(type){
}
int UnaryInst::execute() {
	int address = instruction::des;
	if (type == "ASS") {
		mem[address] = oprnd1;
	}
	else {
		mem[address] = -oprnd1;
	}
	std::cout << mem[address] << std::endl;
	return -1;
}