#pragma once
#include"globals.h"
#include<iostream>
class instruction {
public:
	instruction();
	virtual int execute() = 0;
	~instruction();
};
instruction::instruction(){
	//std:: cout << "base class constructor\n";
}
instruction::~instruction() {}
