#include <iostream>
#include <fstream>
#include <random>
#include <iterator>
#include <algorithm>

using namespace std;

int main() 
{
	ifstream in("정수 만개");
	vector<int> v{ istream_iterator<int>(in),istream_iterator<int>() };
	//vector<int> v;
	//v.reserve(10000);
	//for (int i = 0; i < 10000; ++i)
	//{
	//	int a;
	//	in >> a;
	//	v.push_back(a);
	//}
	cout << count_if(v.begin(), v.end(), [](int a) {
		return a < 10000; }) << endl;
}
