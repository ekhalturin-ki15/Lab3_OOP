#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>
using namespace std;

//Родительский класс наследования
const vector<string> whereItGrows = { "тундре", "пустыни", "степи", "арктике" };


enum WPlant {tree, bush};

class Plant
{
public:

	virtual void In(stringstream& stream) = 0;
	virtual void Out(ofstream& outfile) = 0;
	virtual void OutFilter(ofstream& outfile) {};
	bool Cmp(shared_ptr<Plant> other);

	virtual void MultiMethod(ofstream& outfile, shared_ptr<Plant> other) = 0;
	virtual void OutWithTree(ofstream& outfile) = 0;
	virtual void OutWithBush(ofstream& outfile) = 0;
	
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