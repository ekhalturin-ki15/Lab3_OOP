#include "Bush.h"

void Bush::Out(std::ofstream& outfile)
{

	outfile << "Это кустарник, ";

	if (0 < month && month <= 12)
	{
		outfile << "месяц цветения - " << watIsMonth[month - 1];

	}
	else
	{
		outfile << "месяц цветения считался некорректно";
	}

	outfile << ", Его название: " << name;

	OutSuffix(outfile);

	outfile << std::endl;

}


void Bush::In(std::ifstream& infile)
{
	std::string s;
	infile >> this->month >> this->name >> this->WIG;

}