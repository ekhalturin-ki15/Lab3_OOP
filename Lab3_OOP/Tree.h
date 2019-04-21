#pragma once

#include <fstream>
#include "Plant.h"


class Tree : public Plant
{
public:

	bool In(std::stringstream& stream);
	void Out(std::ofstream& outfile);
	void OutFilter(std::ofstream& outfile);

private:
	__int64 year = 0;
};