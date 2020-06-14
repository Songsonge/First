#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int main()
{
	ifstream in("�ȷ� Ȩ���� ����.txt");

	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
	cout << "1��. �ܾ� ����: " << v.size() << endl;
	cout << endl;



	cout << "2��." << *max_element(v.begin(), v.end(), [](string a, string b) {
		return a.length() < b.length(); }) << endl;
	cout << endl;



	for (auto& p : v)
	{
		for (int i = 0; i < p.size(); ++i)
		{
			p[i] = tolower(p[i]);
		}
	}

	map<string,int> m;
	for (auto p : v)
	{
		m[p]++;
	}
	cout << "3��. �ܾ� ����: " << m.size() << endl;
	cout << endl;





	map<int, string> m2;
	for (auto i : m)
	{
		m2[i.second]=i.first;
	}

	//for (auto i : m2)
	//{
	//	cout << i.first<<" - "<<i.second << endl;
	//}

	cout << "4��. ���� ���� �ܾ�: " << endl;
	auto a = m2.rbegin();
	for (int i = 0; i < 5; ++i)
	{
		cout << a->first << " - " << a->second << endl;
		++a;
	}
	cout << endl;




	ofstream out("e���� �ܾ�.txt");
	int num = 0;

	for (auto i : m)
	{
		string s = i.first;
		bool b=true;
		for (int j=0; j < s.size(); ++j)
		{
			if (s[j] == 'e')
			{
				b = false;
			}
		}
		if (b)
		{
			out << s << endl;
			++num;
		}
	}

	cout << "5��. e���� �ܾ� ����: " << num << endl;




}