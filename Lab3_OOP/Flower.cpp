#include "Flower.h"


void Flower::Out(std::ofstream& outfile)
{

	outfile << "Это цветок, ";
	OutPref(outfile);
	outfile << "тип цветка - " << watIsType[type - 1];
	outfile << "тип считался некорректно";
	outfile << ", Его название: " << name;
	OutSuffix(outfile);
	outfile << std::endl;

}


bool Flower::In(std::stringstream& stream)
{
	std::string s;
	stream >> this->type >> this->name >> this->WIG;
	if ((1 > type) || (type >watIsType.size()) )
		return false;

	return trueWIG(this->WIG);
}