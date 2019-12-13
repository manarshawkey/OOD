#pragma once
#include<iostream>
#include<string>
#include"InstFactory.h"
//#include"globals.h"
#include<vector>
class processor {
public:
	processor();
	void execute_program(std::string);
private:
	InstFactory factory;
	void parse(std::string);
	std::vector<instruction*> inst_mem;
};
processor::processor() {}
void processor::execute_program(std::string file_path) {     //put the call in a try and catch block
	try {
		parse(file_path);
	}
	catch (std::exception e) {
		std::cout << e.what();
	}
	bool halt = 0;
	int res;
	for (int pc = 0; pc < inst_mem.size(); pc++) {
		try
		{
			res = inst_mem[pc]->execute();
		}
		catch (const std::exception& e)
		{
			std::cout << "Error reported while program execution: " << e.what() << std::endl;
		}
		if (res == 0)
			continue;
		if (res == -1) {
			halt = 1;
			break;
		}
		else
			pc = res - 1;
	}
	if (!halt)
		throw std::exception("no halt command to terminate the execution!\n");
}
void processor::parse(std::string path) {
	factory.parse(path, inst_mem);
}
