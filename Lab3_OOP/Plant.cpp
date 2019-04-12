#include "Plant.h"

void Plant::OutSuffix(std::ofstream& outfile)
{
	outfile << " ;";
	if ((0 < WIG) && (WIG <= whereItGrows.size()))
	{
		outfile << " Растёт в " << whereItGrows[WIG - 1];
	}
	else
	{
		outfile << " Местность введенна некорректно";
	}
}