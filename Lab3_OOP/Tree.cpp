#include "Tree.h"

void Tree::Out(std::ofstream& outfile)
{
	outfile << "Это дерево, ";
	OutPref(outfile);
	outfile << "ему " << year << " лет, ";

	outfile << "Его название: " << name << "\n";
}


void Tree::In(std::ifstream& infile)
{
	infile >> this->year >> this->name;
	this->key = Type::tree;
}