#include "Plant.h"
#include <set>

int Plant::AmountConsonant()
{
	int all = 0;

	std::vector<char> bad = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' , '�', '�', '�' }; //��������
	std::set<char> consonant;
	for (char ch = '�'; ch <= '�'; ch++) consonant.insert(ch);
	for (char ch = '�'; ch <= '�'; ch++) consonant.insert(ch);
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
	if ((ch >= '�') && (ch <= '�')) return ch - '�' + '�';
	if ((ch >= '�') && (ch <= '�')) return ch - '�' + '�';
	if (ch == '�') return '�';
	return ch;
}

void Plant::OutPref(std::ofstream& outfile)
{
	outfile << "���������� ��������� =" << AmountConsonant() << " ; ";
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
		outfile << " ����� � " << whereItGrows[WIG - 1];
	}
	else
	{
		outfile << " ��������� �������� �����������";
	}
}