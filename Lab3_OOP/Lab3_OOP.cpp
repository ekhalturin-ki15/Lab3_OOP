#include <iostream>
#include <fstream>
#include <string>
#include "RingList.h"

const int STAND_AMOUNT = 3;

int main(int amount, char* param[])
{

	setlocale(LC_ALL, "Russian");

	std::ifstream infile;
	std::ofstream outfile;

	if (amount == STAND_AMOUNT)
	{
		infile.open(param[1]);
		outfile.open(param[2]);
	}
	else
	{
		infile.open("in.txt");
		outfile.open("out.txt");
	}


	std::cout << "Старт" << std::endl;

	RingList<shared_ptr<Plant>> container;

	container.In(infile);

	std::cout << "Данные считаны с файла" << std::endl;

	container.MultiOut(outfile);

	std::cout << "Данные выведенны в файл" << std::endl << "количество объектов: " << container.WatAmount() << std::endl;

	
	outfile << "---------------------\n";

	std::cout << "Контейнер очищен" << std::endl << "количество объектов: " << container.WatAmount() << std::endl;
	
	container.Clear();
	container.Out(outfile);

	std::cout << "Финиш" << std::endl;
}