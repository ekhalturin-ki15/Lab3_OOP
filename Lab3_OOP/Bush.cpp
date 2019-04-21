#include "Bush.h"

void Bush::Out(std::ofstream& outfile)
{

	outfile << "Это кустарник, ";
	OutPref(outfile);
	if (0 < month && month <= watIsMonth.size())
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


void Bush::In(std::stringstream& stream)
{
	std::string s;
	stream >> this->month >> this->name >> this->WIG;
}

void Bush::MultiMethod(ofstream& outfile, shared_ptr<Plant> other)
{
	other->OutWithBush(outfile);
}
void Bush::OutWithTree(ofstream& outfile)
{
	outfile << "Куст с деревом: ";
}
void Bush::OutWithBush(ofstream& outfile)
{
	outfile << "Куст с кустом: ";
}