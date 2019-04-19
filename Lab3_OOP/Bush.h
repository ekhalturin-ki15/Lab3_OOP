#pragma once

#include <fstream>
#include "Plant.h"

const std::vector<std::string> watIsMonth = { "январь", "февраль", "март", "апрель", "май","июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" };


class Bush : public Plant
{
public:

	void In(std::stringstream& stream);
	void Out(std::ofstream& outfile);

private:
	int month = 0;
};