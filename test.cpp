#include<iostream>
#include<string>
#include<vector>
#include"processor.h"
using namespace std;
int main() {
	//testing changes!kjkkjn
	for (int i = 1; i < 11; i++);
		//mem[i] = i;
	std::string path = "input.txt";
	processor p;
	p.execute_program(path);
	for (int i = 1; i < 11; i++) {
		//std::cout << mem[i];
	}

	return 0;
}