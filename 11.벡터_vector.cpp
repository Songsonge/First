#include <iostream>
#include <array> 
#include <vector>
#include <random>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <fstream>
#include "String.h"

using namespace std;

uniform_int_distribution<> uid(1, 100000000);

default_random_engine dre;



int main()
{
	vector<int> v;

	v.reserve(100000);

	ofstream out("�̷��Ե� ����غ���");

	vector<int> v1;
	v1.reserve(10000);

	for (int i = 0; i < 100000; ++i)
	{
		v.push_back(i);
	}

	copy(v.begin(), v.end(), ostream_iterator<int>(out, "\n"));


	//for (auto d : v) // ���� ��� ����
	//   cout << d << endl;


	//for (int i = 0; i < 10000; ++i)
	//   cout << v[i] << endl;

	//copy(v.begin(), v.end(), ostream_iterator<int>(cout,"\n"));

	//for (auto iter = v.begin(); iter != v.end(); ++iter)
	//{
	//   cout << *iter << endl;
	//}


	//copy(v.begin(), v.end(), ostream_iterator<int>(cout));
	//copy(����,��,������)
	//1. copy(����,��,����)
	//2. copy(����,��,cmd)
	//3. copy(����,��,�����̳�)

}