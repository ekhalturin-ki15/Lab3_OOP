#pragma once
#include "Plant.h"
#include <fstream>

class Tree : public Plant
{
public:

	void In(std::stringstream& stream);
	void Out(std::ofstream& outfile);

	void MultiMethod(ofstream& outfile, shared_ptr<Plant> other);
	void OutWithTree(ofstream& outfile);
	void OutWithBush(ofstream& outfile);

	void OutFilter(std::ofstream& outfile);

private:
	__int64 year = 0;
};