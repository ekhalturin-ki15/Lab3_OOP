#include "Plant.h"

void Plant::OutSuffix(std::ofstream& outfile)
{
	outfile << " ;";
	if ((0 < WIG) && (WIG <= whereItGrows.size()))
	{
		outfile << " ����� � " << whereItGrows[WIG - 1];
	}
	else
	{
		outfile << " ��������� �������� �����������";
	}
}