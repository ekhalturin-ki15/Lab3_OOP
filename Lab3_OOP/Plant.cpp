#include "Plant.h"
#include <set>

int Plant::AmountConsonant()
{
	int all = 0;

	std::vector<char> bad = { 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я' , 'ъ', 'ь', 'ы' }; //Исправил
	std::set<char> consonant;
	for (char ch = 'а'; ch <= 'п'; ch++) consonant.insert(ch);
	for (char ch = 'р'; ch <= 'я'; ch++) consonant.insert(ch);
	for (auto it : bad) consonant.erase(it);

	for (auto it : name)
	{
		if (consonant.count(MyTolower(it)))
			all++;
	}

	return all;
}

char Plant::MyTolower(char ch)
{
	if ((ch >= 'А') && (ch <= 'П')) return ch - 'А' + 'а';
	if ((ch >= 'Р') && (ch <= 'Я')) return ch - 'Р' + 'р';
	if (ch == 'Ё') return 'ё';
	return ch;
}

void Plant::OutPref(std::ofstream& outfile)
{
	outfile << "Количество согласных =" << AmountConsonant() << " ; ";
}

bool Plant::Cmp(shared_ptr<Plant> other)
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