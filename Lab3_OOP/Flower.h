#pragma once

#include <fstream>
#include "Plant.h"

const std::vector<std::string> watIsType = { "домашние", "садовые", "дикие", "редкие", "горные" };

class Flower : public Plant
{
public:

	void In(std::stringstream& stream);
	void Out(std::ofstream& outfile);

	void MultiMethod(ofstream& outfile, shared_ptr<Plant> other);
	void OutWithTree(ofstream& outfile);
	void OutWithBush(ofstream& outfile);

private:
	int type = 0;
};