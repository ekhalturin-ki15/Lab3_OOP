#include "Plant.h"
#include <set>

int Plant::AmountConsonant()
{
	int all = 0;
	std::set<char> gl = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' };
	for (auto it : name)
		if (!gl.count(tolower(it)))
			all++;

	return all;
}

void Plant::OutPref(std::ofstream& outfile)
{
	outfile << "Количество согласных =" << AmountConsonant() << " ; ";
}

bool Plant::cmp(Plant* other)
{
	int l = this->AmountConsonant();
	int r = other->AmountConsonant();
	return (l < r);
}

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