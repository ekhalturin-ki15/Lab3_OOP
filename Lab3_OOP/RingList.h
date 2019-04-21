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

	// Положить в конец
	void PushBack(DataRL flower);

	shared_ptr<ElementRL<DataRL>> begin();

	////Удалить (теперь не настолько выжно, используем умные указатели)
	void Clear();

	void In(std::ifstream& infile);

	void Out(std::ofstream& outfile, bool filter = false);

	void MultiOut(std::ofstream& outfile);

	int WatAmount();

	//Опять не по канонам std, ну да ладно, стерплю
	void Sort();
	
#ifndef UNITTEST
private:
#endif

	shared_ptr<ElementRL<DataRL>> start;
	int amountEl;
	void QSort(vector<shared_ptr<ElementRL<DataRL>>>& mass, int l, int r);

};



//При использовании шаблонов, реализацию нельзя разделять, так как она требуется на этапе компановки

template <typename  DataRL>
void RingList<DataRL>::Out(std::ofstream& outfile, bool filter)
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
void RingList<DataRL>::MultiOut(std::ofstream& outfile)
{
	shared_ptr<ElementRL<DataRL>> it = this->begin();
	shared_ptr<ElementRL<DataRL>> et;
	for (int i = 0; i < this->amountEl; i++)
	{
		et = it->next;
		for (int j = i+1; j < this->amountEl; j++)
		{
			et->data->MultiMethod(outfile, it->data);
			outfile << std::endl;
			it->data->Out(outfile);
			et->data->Out(outfile);
			outfile << std::endl;
			et = et->next;
		}
		it = it->next;
	}
}

template <typename  DataRL>
void RingList<DataRL>::In(std::ifstream& infile)
{
	int type;
	string line;
	stringstream stream;
	
	while (getline(infile, line))
	{
		stream.clear();
		stream.str(line);
		stream >> type;
		shared_ptr<Plant> object;
		//Plant* object = 0;
		switch (type-1)
		{
		case(WPlant::tree):
		
				object = make_shared<Tree>();
				break;
		case(WPlant::bush):
	
				object = make_shared<Bush>();
				break;

		case(WPlant::flower):

			object = make_shared<Flower>();
			break;
		}
		object->In(stream);
		this->PushBack(object);
	}
}

template <typename  DataRL>
RingList<DataRL>::RingList()
{
	amountEl = 0;
	start = 0;
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