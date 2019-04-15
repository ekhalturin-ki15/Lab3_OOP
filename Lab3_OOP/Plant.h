#pragma once

#include <string>
#include <vector>
#include <fstream>

//Родительский класс наследования
const std::vector<std::string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };

const int TREE = 1;
const int BUSH = 2;
const int FLOW = 3;

class Plant
{
public:

	virtual void In(std::ifstream& infile) = 0;
	virtual void Out(std::ofstream& outfile) = 0;
	virtual void OutFilter(std::ofstream& outfile) {};
	bool Cmp(Plant* other);


protected:
	std::string name;
	void OutPref(std::ofstream& outfile);
	int AmountConsonant();
	int WIG;
	void OutSuffix(std::ofstream& outfile);
};