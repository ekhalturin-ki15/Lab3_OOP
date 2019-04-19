#include "CppUnitTest.h"
#include "../Lab3_OOP/Plant.h"
#include "../Lab3_OOP/Tree.h"
#include "../Lab3_OOP/Bush.h"
#include "../Lab3_OOP/Flower.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlantTest
{
	string GetMaxName(int length)
	{
		string s;
		for (int i = 0; i < length; i++) s.push_back('п');
		return s;
	}

	string GetMinName(int length)
	{
		string s;
		for (int i = 0; i < length; i++) s.push_back('ь');
		return s;
	}

	TEST_CLASS(TestCmp)
	{
	private:
		string name;
		shared_ptr<Plant> first;
		shared_ptr<Plant> second;
		shared_ptr<Plant> last;
		const int LENG = 50;

	public:
		TestCmp()
		{
			first = make_shared<Tree>();
			second = make_shared<Tree>();
			last = make_shared<Tree>();
	
			stringstream stream;
			stream.clear();
			name = GetMinName(LENG);
			stream.str("100 " + name + " 4");
			first->In(stream);


			stream.clear();
			name = GetMaxName(LENG);
			stream.str("100 " + name + " 4");
			last->In(stream);
			
			name[0] = ' ';
			stream.clear();
			stream.str("100 " + name + " 4");
			second->In(stream);
		}

		TEST_METHOD(Left1)
		{
			Assert::IsTrue(first->Cmp(second));
		}

		TEST_METHOD(Left2)
		{
			Assert::IsTrue(second->Cmp(last));
		}

		TEST_METHOD(Left3)
		{
			Assert::IsTrue(first->Cmp(last));
		}

		TEST_METHOD(Right1)
		{
			Assert::IsFalse(second->Cmp(first));
		}

		TEST_METHOD(Right2)
		{
			Assert::IsFalse(last->Cmp(second));
		}

		TEST_METHOD(Right3)
		{
			Assert::IsFalse(last->Cmp(first));
		}

		TEST_METHOD(Equal_)
		{
			Assert::IsFalse(first->Cmp(first));
		}
	};


	TEST_CLASS(TestAmountConsonant)
	{
	private:
		shared_ptr<Plant> tree;
		shared_ptr<Plant> bush;
		shared_ptr<Plant> flower;
	public:

		TestAmountConsonant()
		{
			tree = make_shared<Tree>();
			bush = make_shared<Bush>();
			flower = make_shared<Flower>();
		}

		TEST_METHOD(TestTree)
		{
			stringstream stream;
			stream.str("100 ДеревКоъыЫ");
			tree->In(stream);
			Assert::AreEqual(4, tree->AmountConsonant());
		}

		TEST_METHOD(TestTreeUpper)
		{
			stringstream stream;
			stream.str("100 ldfsLfdlslДДТЁОО ОО");
			tree->In(stream);
			Assert::AreEqual(3, tree->AmountConsonant());
		}

		TEST_METHOD(TestBush)
		{
			stringstream stream;
			stream.str("-10 БруСниККа");
			bush->In(stream);
			Assert::AreEqual(6, bush->AmountConsonant());
		}

		TEST_METHOD(TestBushUpper)
		{
			stringstream stream;
			stream.str("-0 RECNB~RКУСТИЁК 5 5 5 5 ");
			bush->In(stream);
			Assert::AreEqual(4, bush->AmountConsonant());
		}

		TEST_METHOD(TestFlower)
		{
			stringstream stream;
			stream.str("-10 ЦвеТочекК");
			flower->In(stream);
			Assert::AreEqual(6, flower->AmountConsonant());
		}

		TEST_METHOD(TestFlowerUpper)
		{
			stringstream stream;
			stream.str("-0 VBHМИРоВООЙЙ hello 2423");
			flower->In(stream);
			Assert::AreEqual(5, flower->AmountConsonant());
		}
	};

	TEST_CLASS(TestOutFilter)
	{
	public:
		TestOutFilter()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			
		}

		TEST_METHOD(TestTree)
		{
			obj = make_shared<Tree>();
			obj->OutFilter(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это дерево, Количество согласных =0 ; ему 0 лет, Его название:  ; Местность введенна некорректно"), s);
		}
		TEST_METHOD(TestBush)
		{
			obj = make_shared<Bush>();
			obj->OutFilter(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string(""), s);
		}
		TEST_METHOD(TestFlower)
		{
			obj = make_shared<Flower>();
			obj->OutFilter(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string(""), s);
		}

	private:
		ofstream out;
		ifstream in;
		shared_ptr<Plant> obj;
	};

	TEST_CLASS(TestMyTolower)
	{
	public:


		TEST_METHOD(Test1)
		{
			obj = make_shared<Tree>();
			Assert::AreEqual('п',obj->MyTolower('П'));
		}
	
		TEST_METHOD(Test2)
		{
			obj = make_shared<Tree>();
			Assert::AreEqual('W', obj->MyTolower('W'));
		}
		TEST_METHOD(Test3)
		{
			obj = make_shared<Tree>();
			Assert::AreEqual('п', obj->MyTolower('п'));
		}

	private:
		shared_ptr<Plant> obj;
	};

	TEST_CLASS(TestOutPref)
	{
	public:
		TestOutPref()
		{
			in.open("input test.txt");
			out.open("input test.txt");

		}

		TEST_METHOD(Test1)
		{
			obj = make_shared<Bush>();
			obj->OutPref(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Количество согласных =0 ; "), s);
		}
		TEST_METHOD(TestFlower)
		{
			obj = make_shared<Flower>();
			obj->name = "Ромашка";
			obj->OutPref(out);			
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Количество согласных =4 ; "), s);
		}

	private:
		ofstream out;
		ifstream in;
		shared_ptr<Plant> obj;
	};

	TEST_CLASS(TestOutSuffix)
	{
	public:
		TestOutSuffix()
		{
			in.open("input test.txt");
			out.open("input test.txt");

		}

		TEST_METHOD(Test1)
		{
			obj = make_shared<Bush>();
			obj->OutSuffix(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string(" ; Местность введенна некорректно"), s);
		}
		TEST_METHOD(TestFlower)
		{
			obj = make_shared<Flower>();
			obj->WIG = 3;
			obj->OutSuffix(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string(" ; Растёт в степи"), s);
		}

	private:
		ofstream out;
		ifstream in;
		shared_ptr<Plant> obj;
	};
}

namespace BushTest
{

	TEST_CLASS(TestIn)
	{
	public:

		TestIn()
		{
			stringstream stream;
			stream.str("2 Куст 4");
			obj = make_shared<Bush>();
			obj->In(stream);
			obj2 = make_shared<Bush>();
		}
		TEST_METHOD(Test1)
		{
			Assert::AreEqual(string("Куст"), obj->name);
		}
		TEST_METHOD(Test2)
		{
			Assert::AreEqual(4, obj->WIG);
		}

		TEST_METHOD(TestEmpty1)
		{
			Assert::AreEqual(string(""), obj2->name);
		}

		TEST_METHOD(TestEmpty2)
		{
			Assert::AreEqual(0, obj2->WIG);
		}

	private:
		shared_ptr<Plant> obj;
		shared_ptr<Plant> obj2;
	};

	TEST_CLASS(TestOut)
	{
	public:
		TestOut()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			stringstream stream;
			stream.str("2 Куст 4");
			obj = make_shared<Bush>();
			obj->In(stream);
			obj2 = make_shared<Bush>();
		}

		TEST_METHOD(Test)
		{	
			obj->Out(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это кустарник, Количество согласных =3 ; месяц цветения - февраль, Его название: Куст ; Растёт в арктике"), s);
		}
		TEST_METHOD(TestEmpty)
		{
			obj2->Out(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это кустарник, Количество согласных =0 ; месяц цветения считался некорректно, Его название:  ; Местность введенна некорректно"), s);
		}

	private:
		ofstream out;
		ifstream in;
		shared_ptr<Plant> obj;
		shared_ptr<Plant> obj2;
	};
}


namespace TreeTest
{

	TEST_CLASS(TestIn)
	{
	public:

		TestIn()
		{
			stringstream stream;
			stream.str("1 Деревко 3");
			obj = make_shared<Tree>();
			obj->In(stream);
			obj2 = make_shared<Tree>();
		}
		TEST_METHOD(Test1)
		{
			Assert::AreEqual(string("Деревко"), obj->name);
		}
		TEST_METHOD(Test2)
		{
			Assert::AreEqual(3, obj->WIG);
		}

		TEST_METHOD(TestEmpty1)
		{
			Assert::AreEqual(string(""), obj2->name);
		}

		TEST_METHOD(TestEmpty2)
		{
			Assert::AreEqual(0, obj2->WIG);
		}

	private:
		shared_ptr<Plant> obj;
		shared_ptr<Plant> obj2;
	};

	TEST_CLASS(TestOut)
	{
	public:
		TestOut()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			stringstream stream;
			stream.str("1 Деревко 2");
			obj = make_shared<Tree>();
			obj->In(stream);
			obj2 = make_shared<Tree>();
		}

		TEST_METHOD(Test)
		{
			obj->Out(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это дерево, Количество согласных =4 ; ему 1 лет, Его название: Деревко ; Растёт в пустыни"), s);
		}
		TEST_METHOD(TestEmpty)
		{
			obj2->Out(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это дерево, Количество согласных =0 ; ему 0 лет, Его название:  ; Местность введенна некорректно"), s);
		}

	private:
		ofstream out;
		ifstream in;
		shared_ptr<Plant> obj;
		shared_ptr<Plant> obj2;
	};
}

namespace FlowerTest
{

	TEST_CLASS(TestIn)
	{
	public:

		TestIn()
		{
			stringstream stream;
			stream.str("5 Цветочек 2");
			obj = make_shared<Flower>();
			obj->In(stream);
			obj2 = make_shared<Flower>();
		}
		TEST_METHOD(Test1)
		{
			Assert::AreEqual(string("Цветочек"), obj->name);
		}
		TEST_METHOD(Test2)
		{
			Assert::AreEqual(2, obj->WIG);
		}

		TEST_METHOD(TestEmpty1)
		{
			Assert::AreEqual(string(""), obj2->name);
		}

		TEST_METHOD(TestEmpty2)
		{
			Assert::AreEqual(0, obj2->WIG);
		}

	private:
		shared_ptr<Plant> obj;
		shared_ptr<Plant> obj2;
	};

	TEST_CLASS(TestOut)
	{
	public:
		TestOut()
		{
			in.open("input test.txt");
			out.open("input test.txt");
			stringstream stream;
			stream.str("3 Цветочек 1");
			obj = make_shared<Flower>();
			obj->In(stream);
			obj2 = make_shared<Flower>();
		}

		TEST_METHOD(Test)
		{
			obj->Out(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это цветок, Количество согласных =5 ; тип цветка - дикие, Его название: Цветочек ; Растёт в тундре"), s);
		}
		TEST_METHOD(TestEmpty)
		{
			obj2->Out(out);
			out.close();
			string s;
			getline(in, s);
			Assert::AreEqual(string("Это цветок, Количество согласных =0 ; тип считался некорректно, Его название:  ; Местность введенна некорректно"), s);
		}

	private:
		ofstream out;
		ifstream in;
		shared_ptr<Plant> obj;
		shared_ptr<Plant> obj2;
	};
}