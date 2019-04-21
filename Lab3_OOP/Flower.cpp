#include "Flower.h"


void Flower::Out(std::ofstream& outfile)
{

	outfile << "Это цветок, ";
	OutPref(outfile);

	if (1<=type && type <= watIsType.size())
	{
		outfile << "тип цветка - " << watIsType[type - 1];
	}
	else
	{
		outfile << "тип считался некорректно";
	}

	outfile << ", Его название: " << name;

	OutSuffix(outfile);

	outfile << std::endl;

}


void Flower::In(std::stringstream& stream)
{
	std::string s;
	stream >> this->type >> this->name >> this->WIG;
}


void Flower::MultiMethod(ofstream& outfile, shared_ptr<Plant> other)
{
	other->OutWithBush(outfile);
}
void Flower::OutWithTree(ofstream& outfile)
{
	outfile << "Куст с деревом: ";
}
void Flower::OutWithBush(ofstream& outfile)
{
	outfile << "Куст с кустом: ";
}