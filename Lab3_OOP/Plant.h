#pragma once

#include <string>
#include <vector>
#include <fstream>

//Родительский класс наследования

enum Type { tree, bush };

class Plant
{
public:

	virtual void In(std::ifstream& infile) = 0;
	virtual void Out(std::ofstream& outfile) = 0;

	Type key;


protected:
	std::string name;
};