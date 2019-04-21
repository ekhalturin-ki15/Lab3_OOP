#pragma once

#include "Plant.h"
#include <fstream>

const std::vector<std::string> watIsMonth = { "январь", "февраль", "март", "апрель", "май","июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };


class Bush : public Plant
{
public:

	void In(std::stringstream& stream);
	void Out(std::ofstream& outfile);

	void MultiMethod(ofstream& outfile, shared_ptr<Plant> other);
	void OutWithTree(ofstream& outfile);
	void OutWithBush(ofstream& outfile);


private:
	int month = 0;
};