	#include <iostream>
	#include<vector>
	#include<string>
#include<algorithm>
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
		//without t
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
	void prints(const vector<string> arrstr)
	{
			for (size_t i = 0; i < arrstr.size(); i++)
			{
				cout <<arrstr[i] << endl;
			}
		
	}
	// find sum char in line
	int counT(const string& s, char c)
	{
		int g = 0;
		string::const_iterator i = find(s.begin(), s.end(), c);
		while (i != s.end())
		{
			++g;
			i = find(i + 1, s.end(), c);
		}
		return g;
	}
	// find sum several char in line
	int counT(const string& s, const string& c)
	{
		int counter = 0;
		for (size_t i = 0; i < s.length(); i++)
		{
			if (s.at(i) == c.at(0))
			{
				if (s.at(i + 1) == c.at(1))
				{
					counter++;
				}
			}
		}
		return counter;
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
		//transfer array in function, Instead of the usual array, it is better to use a vector
		//vector <string> str = { "a", "s", "c" };
		//prints(str);

		//Reading words from a stream without repeating and sorting
		//string st; 
		//vector<string> vec;
		//while (cin >> st&&st != "Quit")
		//{
		//	int f = 0;
		//	for each (string var in vec)
		//	{
		//		if (st==var)
		//		{
		//			f++;
		//			
		//		}
		//	}
		//	if (f==0)
		//	{
		//		vec.push_back(st);
		//	}
		//	
		//}
		////show vector
		//for each (string var in vec)
		//{
		//	cout << var << endl;
		//}
		//sort(vec.begin(), vec.end());
		//for each (string var in vec)
		//{
		//	cout << var << endl;
		//}
			//Count the number of repeats of a pair of letters
		string str = { "abasasbabdabeew" };
		char a = 'a';
		string f = { "ab" };
		cout<<counT(str, a)<<endl;
		cout << counT(str, f) << endl;
		
		
	}

	