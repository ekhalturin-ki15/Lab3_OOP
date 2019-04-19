#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

//Родительский класс наследования
const vector<string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };

const int TREE = 1;
const int BUSH = 2;
const int FLOW = 3;

class Plant
{
public:

	virtual void In(stringstream& stream) = 0;
	virtual void Out(ofstream& outfile) = 0;
	virtual void OutFilter(ofstream& outfile) {};
	bool Cmp(shared_ptr<Plant> other);
	
#ifndef UNITTEST
protected:
#endif
	string name ="";
	int WIG = 0;
	int AmountConsonant();
	void OutPref(ofstream& outfile);
	char MyTolower(char ch);
	void OutSuffix(ofstream& outfile);
};