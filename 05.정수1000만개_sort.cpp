#include <iostream>
#include <fstream>
#include <algorithm>
#include <random>

using namespace std;

int main()
{
	default_random_engine dre;
	uniform_int_distribution<> uid;

	ofstream out(" ���� 1000����.data", ios::binary);
	int n;
	/*for (int i = 0; i < 1000'0000; ++i)
	{
	n = uid(dre);
	if (i % 100000 == 0)
	{
	cout << i << endl;
	}
	out << n << endl;
	}*/

	//out.write()

	ifstream in(" ���� 1000����.data");

	int* p = new int[1000'0000];

	//for (int i = 0; i < 1000'0000; ++i)
	//{
	//   in >> p[i];
	//}

	//in.read()

	cout << "������" << endl;
	sort(&p[0], &p[1000'0000], [](int a, int b) {
		return a < b; });

	ofstream fout("����1000��������.data");

	cout << "�����" << endl;
	for (int i = 0; i < 1000'0000; ++i)
	{
		fout << p[i] << endl;
	}


}