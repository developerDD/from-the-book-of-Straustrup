#include <iostream>
#include<vector>
#include<string>
//����� ���� ������� ����������� � ����� ����� � ���������� (� ������� �������� ���������)

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
void main()
{
	
	string buff;

	while (cin >> buff&&buff != "1")
	{
		value(buff)++;

	}
	for (vector<Pair>::const_iterator p = pairs.begin(); p != pairs.end(); ++p)
	{
		cout << p->name << ":" << p->vel << "\n";
	}

}