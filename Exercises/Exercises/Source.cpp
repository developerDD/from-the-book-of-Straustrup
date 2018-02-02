	#include <iostream>
	#include<vector>
	#include<string>
	//поиск слов которые повторяются и вывод слова и количества (с помощью создания структуры)

	using namespace std;

	struct Pair
	{
		string name;
		double vel;

	};
	vector<Pair> pairs;

	double& value(const string& s)
	{
		for (size_t i = 0; i < pairs.size(); i++)
		{
			if (pairs[i].name == s)
			{
				return pairs[i].vel;
			}
		}
		Pair p = { s, 0 };
		pairs.push_back(p);
		return pairs[pairs.size() - 1].vel;

	}

	void f(int* a, int* b)
	{
		/*int t;
		t = *a;
		*a = *b;
		*b = t;*/
		//whit out t
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
	void f2(int& a, int& b)
	{
		a = a + b;
		b = a - b;
		a = a - b;
	}
	void prints(string* arrstr)
	{
		
			for (int i = 0; i < 3; i++)
			{
				cout << *(arrstr + i) << "/" << arrstr[i] << endl;
			}
		
	}
	void main()
	{

		/*string buff;

		while (cin >> buff&&buff != "1")
		{
		value(buff)++;

		}
		for (vector<Pair>::const_iterator p = pairs.begin(); p != pairs.end(); ++p)
		{
		cout << p->name << ":" << p->vel << "\n";
		}*/
		// initialize the variables
		//char D = 'D';
		//char* pch = &D;
		//int arr[10] = {};
		//string* pstr = new string[10];
		//char** ppch = &pch;
		//const int ci = 1;
		//const int* pci = &ci;
		//const int* const cpci = pci;
		////use typedef
		//typedef unsigned char  uchar;
		//typedef const unsigned char cuchar; 
		//typedef int* pint;		//pointer on int 
		//typedef char** ppchar; //pointer on pointer on char
		//typedef char* parrchar; //array pointer
		//
		//pint array_pointer[7];
		//int** ppint = array_pointer;
		//ppint[8];

		//int a = 1;
		//int b = 2;
		//int* pa; int* pb;
		//pa = &a;
		//pb = &b;
		//cout << a <<" "<< b << "\n";
		//f(pa, pb);
		//cout << a << " " << b << "\n";
		//f2(a, b);
		//cout << a << " " << b << "\n";

		//char str[] = "a short string";
		//int intv[] = { 1, 2, 3 };
		//cout << sizeof(str) << " " << sizeof(str) / sizeof(char) << "\n";
		//cout << sizeof(intv) << " " << sizeof(intv) / sizeof(int);
		////use pointer and idex
		//for (size_t i = 0; i < sizeof(str); i++)
		//{
		//	cout << *(str + i) << "\\"<<str[i]<<"\n";
		//}
		//transfer array in function
		string arrstr[] = { "a", "s", "c" };
		
		prints(arrstr);

		
	}

	