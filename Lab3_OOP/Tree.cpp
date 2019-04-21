﻿#include "Tree.h"

void Tree::Out(std::ofstream& outfile)
{
	outfile << "Это дерево, ";
	OutPref(outfile);
	outfile << "ему " << year << " лет, ";

	outfile << "Его название: " << name;

	OutSuffix(outfile);

	outfile << std::endl;
}

void Tree::OutFilter(std::ofstream& outfile)
{
	outfile << "Это дерево, ";
	OutPref(outfile);
	outfile << "ему " << year << " лет, ";
	outfile << "Его название: " << name;
	OutSuffix(outfile);
	outfile << std::endl;
}

bool Tree::In(std::stringstream& stream)
{
	stream >> this->year >> this->name >> this->WIG;
	if (year < 1) return false;
	return trueWIG(this->WIG);
}