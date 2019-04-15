#pragma once

#include <string>
#include <vector>
#include <fstream>

//Родительский класс наследования
const std::vector<std::string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };

enum Type { tree, bush, flower };

class Plant
{
public:

	virtual void In(std::ifstream& infile) = 0;
	virtual void Out(std::ofstream& outfile) = 0;
	virtual void OutFilter(std::ofstream& outfile) {};

	bool cmp(Plant* other);
	Type key;


protected:
	std::string name;
	void OutPref(std::ofstream& outfile);
	int AmountConsonant();
	int WIG;
	void OutSuffix(std::ofstream& outfile);
};