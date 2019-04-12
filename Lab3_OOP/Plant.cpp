#include "Plant.h"
#include <set>

int Plant::AmountConsonant()
{
	int all = 0;
	std::set<char> gl = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
	for (auto it : name)
		if (!gl.count(tolower(it)))
			all++;

	return all;
}

void Plant::OutPref(std::ofstream& outfile)
{
	outfile << "���������� ��������� =" << AmountConsonant() << " ; ";
}