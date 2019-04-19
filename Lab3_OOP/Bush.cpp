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