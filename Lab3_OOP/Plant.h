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

	bool cmp(Plant* other);
	Type key;


protected:
	std::string name;
	void OutPref(std::ofstream& outfile);
	int AmountConsonant();
};