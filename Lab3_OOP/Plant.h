#pragma once

#include <string>
#include <vector>
#include <fstream>

//Родительский класс наследования
const std::vector<std::string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };

class Plant
{
public:

	virtual void In(std::ifstream& infile) = 0;
	virtual void Out(std::ofstream& outfile) = 0;



protected:
	std::string name;
	int WIG;
	void OutSuffix(std::ofstream& outfile);
};