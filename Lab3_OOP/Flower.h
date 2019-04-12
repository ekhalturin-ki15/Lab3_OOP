#pragma once

#include <fstream>
#include "Plant.h"

const std::vector<std::string> watIsType = { "домашние", "садовые", "дикие", "редкие", "горные" };

class Flower : public Plant
{
public:

	void In(std::ifstream& infile);
	void Out(std::ofstream& outfile);


private:
	int type;
};