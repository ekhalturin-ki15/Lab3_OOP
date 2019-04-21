#include "Tree.h"

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

}

void Tree::In(std::stringstream& stream)
{
	stream >> this->year >> this->name >> this->WIG;
}

void Tree::MultiMethod(ofstream& outfile, shared_ptr<Plant> other)
{
	other->OutWithTree(outfile);
}
void Tree::OutWithTree(ofstream& outfile)
{
	outfile << "Дерево с деревом: ";
}
void Tree::OutWithBush(ofstream& outfile)
{
	outfile << "Дерево с кустом: ";
}

void Tree::OutWithFlower(ofstream& outfile)
{
	outfile << "Дерево с цветком: ";
}