#include "Flower.h"


void Flower::Out(std::ofstream& outfile)
{

	outfile << "Это цветок, ";

	if (-1 < type && type < watIsType.size())
	{
		outfile << "тип цветка - " << watIsType[type - 1];

	}
	else
	{
		outfile << "тип считался некорректно";
	}

	outfile << ", Его название: " << name << "\n";

}


void Flower::In(std::ifstream& infile)
{
	std::string s;
	infile >> this->type >> this->name;

}