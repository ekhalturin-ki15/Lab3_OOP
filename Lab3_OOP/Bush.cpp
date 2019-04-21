#include "Bush.h"

void Bush::Out(std::ofstream& outfile)
{
	outfile << "Это кустарник, ";
	OutPref(outfile);
	outfile << "месяц цветения - " << watIsMonth[month - 1];
	outfile << ", Его название: " << name;
	OutSuffix(outfile);
	outfile << std::endl;
}


bool Bush::In(std::stringstream& stream)
{
	std::string s;
	stream >> this->month >> this->name >> this->WIG;
	if ((1 > month) || (month > watIsMonth.size()))
		return false;
	return trueWIG(this->WIG);
}