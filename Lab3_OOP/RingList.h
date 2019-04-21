#pragma once
#include "Plant.h"
#include "Bush.h"
#include "Tree.h"
#include "Flower.h"
#include <memory>
using namespace std;

//Элемент контейнера кольцевой двусвязанный список
template <typename Data>
class ElementRL
{
public:
	Data data;
	shared_ptr<ElementRL<Data>> next;
	shared_ptr<ElementRL<Data>> prev;

};

//Объявление двусвязанного списка
template <typename DataRL>
class RingList
{
public:

	RingList();
	~RingList();

	// Положить в конец
	void PushBack(DataRL flower);

	shared_ptr<ElementRL<DataRL>> begin();

	////Удалить (теперь не настолько выжно, используем умные указатели)
	void Clear();

	void setInpOut(ifstream& in, ofstream& out);

	void In();

	void Out(bool filter = false);

	int WatAmount();

	//Опять не по канонам std, ну да ладно, стерплю
	void Sort();
	
#ifndef UNITTEST
private:
#endif

	bool getPlant(string line);
	int whatLine;
	shared_ptr<ElementRL<DataRL>> start;
	int amountEl;
	void QSort(vector<shared_ptr<ElementRL<DataRL>>>& mass, int l, int r);

	ofstream outfile;
	ifstream infile;
};



//При использовании шаблонов, реализацию нельзя разделять, так как она требуется на этапе компановки
template <typename  DataRL>
void RingList<DataRL>::setInpOut(ifstream& in, ofstream& out)
{
	infile = move(in);
	outfile = move(out);
}



template <typename  DataRL>
void RingList<DataRL>::Out(bool filter)
{
	shared_ptr<ElementRL<DataRL>> it = this->begin();
	for (int i = 0; i < this->amountEl; i++)
	{
		if (filter)
			it->data->OutFilter(outfile);
		else
			it->data->Out(outfile);
		it = it->next;
	}
}

template <typename  DataRL>
void RingList<DataRL>::In()
{
	string line;
	whatLine = 0;
	while (getline(infile, line))
	{
		whatLine++;
		enum Type {tree, bush, flower};
		getPlant(line);
	}
	outfile << "_________________________________\n";
}

template <typename  DataRL>
bool RingList<DataRL>::getPlant(string line)
{
	stringstream stream;
	int type;
	shared_ptr<Plant> object;
	stream.str(line);
	try
	{
		stream >> type;	
		switch (type - 1)
		{
		case (Type::tree):
			object = make_shared<Tree>();
			break;
		case (Type::bush):
			object = make_shared<Bush>();
			break;
		case (Type::flower):
			object = make_shared<Flower>();
			break;
		default:
			throw (string("Неизвестный тип класса - " + to_string(type)));
		}
		if (!object->In(stream))
			throw (string("Неккоректный ввод параметров класса"));
	
		this->PushBack(object);
	}
	catch (string wrong)
	{
		outfile << wrong << " : в строке номер " + to_string(whatLine) << endl;
		return false;
	}
	this->PushBack(object);
	return true;
}


template <typename  DataRL>
RingList<DataRL>::RingList()
{
	whatLine = 0;
	amountEl = 0;
	start = 0;
}

template <typename  DataRL>
RingList<DataRL>::~RingList()
{
	outfile.close();
	infile.close();
}

template <typename  DataRL>
shared_ptr<ElementRL<DataRL>> RingList<DataRL>::begin()
{
	return start;
}


template <typename  DataRL>
void RingList<DataRL>::PushBack(DataRL plant)
{


	shared_ptr<ElementRL<DataRL>> newEl;
	newEl = make_shared<ElementRL<DataRL>>();


	if (start)
	{
		start->prev->next = newEl;
		newEl->prev = start->prev;
		newEl->next = start;
		newEl->data = plant;
		start->prev = newEl;
		start->prev = start->prev;
	}
	else
	{
		start = newEl;
		start->next = start;
		start->prev = start;
		start->data = plant;
	}
	this->amountEl++;
}



//Общий код для конструктора и для очищения контейнера
template <typename  DataRL>
void RingList<DataRL>::Clear()
{
	amountEl = 0;
	start = 0;
}

template <typename  DataRL>
int RingList<DataRL>::WatAmount()
{
	return this->amountEl;
}



template <typename  DataRL>
void RingList<DataRL>::Sort()
{

	vector<shared_ptr<ElementRL<DataRL>>> mass;
	shared_ptr<ElementRL<DataRL>> it = this->begin();
	for (int i = 0; i < this->WatAmount(); i++)
	{
		mass.push_back(it);
		it = it->next;
	}

	this->QSort(mass, 0, mass.size() - 1);


}

template <typename  DataRL>
void RingList<DataRL>::QSort(vector<shared_ptr<ElementRL<DataRL>>>& mass, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r;
	ElementRL<DataRL> p = *mass[(l + r) / 2];
	while (true)
	{
		while (p.data->Cmp(mass[i]->data)) i++;

		while (mass[j]->data->Cmp(p.data)) j--;

		if (i <= j)
		{
			std::swap(mass[i]->data, mass[j]->data);

			i++;
			j--;
		}
		if (i > j) break;
	}

	this->QSort(mass, l, j); //then QuickSort(l, j);
	this->QSort(mass, i, r); //then QuickSort(i, r);
}