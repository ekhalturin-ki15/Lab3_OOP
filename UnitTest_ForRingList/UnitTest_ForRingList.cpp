#include "CppUnitTest.h"
#include "../Lab3_OOP/RingList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestRingList
{
	TEST_CLASS(Create)
	{
	public:
		TEST_METHOD(EmptyP)
		{
			Assert::IsTrue(0 == containerP.begin());
		}

		TEST_METHOD(Empty)
		{
			Assert::AreEqual(0, containerP.WatAmount());
		}
		TEST_METHOD(EmptyI)
		{
			Assert::IsTrue(0 == containerI.begin());
		}

	private:
		RingList<shared_ptr<Plant>> containerP;
		RingList<int> containerI;
	};

	TEST_CLASS(PushBack)
	{
	public:
		PushBack()
		{
			shared_ptr<Plant> plant;
			plant = make_shared<Tree>();
			plant->name = "Первый";
			containerP.PushBack(plant);
			for (int i = 2; i < AMOUNT; i++)
			{
				shared_ptr<Plant> plant;
				plant = make_shared<Tree>();
				plant->name = "Что это такое";
				containerP.PushBack(plant);
			}
			plant = make_shared<Tree>();
			plant->name = "Последний";
			containerP.PushBack(plant);
		}
		TEST_METHOD(AmountP)
		{
			Assert::AreEqual(AMOUNT, containerP.WatAmount());
		}
		TEST_METHOD(TestRing1)
		{
			Assert::AreEqual(string("Первый"), containerP.begin()->prev->next->data->name);
		}
		TEST_METHOD(TestRing2)
		{
			Assert::AreEqual(string("Первый"), containerP.begin()->next->prev->data->name);
		}

		TEST_METHOD(TestRing3)
		{
			Assert::AreEqual(string("Последний"), containerP.begin()->prev->data->name);
		}

	private:
		RingList<shared_ptr<Plant>> containerP;
		const int AMOUNT = 5;
	};

	TEST_CLASS(InTest)
	{
	public:
		InTest()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			out << " 1  12 Дуб 1" << endl << "2  2 Малина  2" << endl << "3  10 Роза 1";
			out.close();
		}
		TEST_METHOD(Test1)
		{
			containerP.In();
			Assert::AreEqual(string("Малина"), containerP.begin()->next->data->name);
		}
		TEST_METHOD(Test2)
		{
			containerP.In();
			Assert::AreEqual(1, containerP.begin()->prev->data->WIG);
		}
		TEST_METHOD(TestAmount)
		{
			containerP.In();
			Assert::AreEqual(3, containerP.WatAmount());
		}
	private:
		RingList<shared_ptr<Plant>> containerP;
		ifstream in;
		ofstream out;
	};

	TEST_CLASS(OutTest)
	{
	public:
		OutTest()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			out << " 1  12 Дуб 1" << endl << "2  2 Малина  2" << endl << "3  10 Роза 1";
			out.close();
	
			containerP.In();
			in.close();
		}
		TEST_METHOD(Test1)
		{
			out.open("input test.txt");
			containerP.Out();
			out.close();
			in.open("input test.txt");
			getline(in, line);
			Assert::AreEqual(string("Это дерево, Количество согласных =2 ; ему 12 лет, Его название: Дуб ; Растёт в тундре"), line);
		}

		TEST_METHOD(Test2)
		{
			out.open("input test.txt");
			containerP.Out();
			out.close();
			in.open("input test.txt");
			for (int i = 0;i<2;i++) getline(in, line);
			Assert::AreEqual(string("Это кустарник, Количество согласных =3 ; месяц цветения - февраль, Его название: Малина ; Растёт в пустыни"), line);
		}

		TEST_METHOD(Test3)
		{
			out.open("input test.txt");
			containerP.Out();
			out.close();
			in.open("input test.txt");
			for (int i = 0; i < 3; i++) getline(in, line);
			Assert::AreEqual(string("Это цветок, Количество согласных =2 ; тип считался некорректно, Его название: Роза ; Растёт в тундре"), line);
		}
		
	private:
		RingList<shared_ptr<Plant>> containerP;
		ifstream in;
		ofstream out;
		string line;
	};

	TEST_CLASS(WhatAmountTest)
	{
	public:
		WhatAmountTest()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			out << " 1  12 Дуб 1" << endl << "2  2 Малина  2" << endl << "3  10 Роза 1";
			out.close();

			containerP.In();
			in.close();
		}
		TEST_METHOD(Test1)
		{
			Assert::AreEqual(3, containerP.WatAmount());
		}
		TEST_METHOD(Test2)
		{
			Assert::AreEqual(containerP.amountEl, containerP.WatAmount());
		}

		
	private:
		RingList<shared_ptr<Plant>> containerP;
		ifstream in;
		ofstream out;
	};

	TEST_CLASS(SortTest)
	{
	public:
		SortTest()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			out << " 2 -12 what 1" << endl << " 3  -12 П 1" << endl << "1  -2 ПП  2" << endl << "1  -10 ППП 1";
			out.close();

			containerP.In();
			in.close();
		}
		TEST_METHOD(Test1)
		{
			containerP.Sort();
			Assert::AreEqual(3, containerP.begin()->data->AmountConsonant());
		}

		TEST_METHOD(Test2)
		{
			containerP.Sort();
			Assert::AreEqual(0, containerP.begin()->prev->data->AmountConsonant());
		}

	private:
		RingList<shared_ptr<Plant>> containerP;
		ifstream in;
		ofstream out;
		string line;
	};

	TEST_CLASS(QSortTest)
	{
	public:
		
		TEST_METHOD(CrushTest)
		{
			containerP.QSort(massP, 0, -1);
			Assert::IsTrue(true);
		}

	private:
		RingList<shared_ptr<Plant>> containerP;
		vector<shared_ptr<ElementRL<shared_ptr<Plant>>>> massP;
	};
}
