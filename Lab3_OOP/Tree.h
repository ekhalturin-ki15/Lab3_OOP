#pragma once

#include <fstream>
#include "Plant.h"


class Tree : public Plant
{
public:

	void In(std::ifstream& infile);
	void Out(std::ofstream& outfile);
	void OutFilter(std::ofstream& outfile);

private:
	__int64 year;
};