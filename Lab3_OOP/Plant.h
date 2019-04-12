#pragma once

#include <string>
#include <vector>
#include <fstream>

//Родительский класс наследования

class Plant
{
public:

	virtual void In(std::ifstream& infile) = 0;
	virtual void Out(std::ofstream& outfile) = 0;



protected:
	std::string name;
	void OutPref(std::ofstream& outfile);
	int AmountConsonant();
};