#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

template <class T,class T2>
T my_max_element(T first, T last, T2 r )
{
	T largest = first;

	while (++first != last)
		if (r(*largest,*first)) 
			largest = first;
	return largest;
}

template<class InputIterator, class OutputIterator>
OutputIterator my_copy(InputIterator first, InputIterator last, OutputIterator result)
{
	while (first != last) {
		*result = *first;
		++result; ++first;
	}
	return result;
}


int main()

{
	ifstream in("�ȷ� Ȩ���� ����.txt");

	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
	cout << "1��. ����: " << v.size() << endl;

	map<string, int> m;
	for (auto p : v)
	{
		m[p]++;
	}

	//1. �־��� ������ ��� �ܾ �����̳ʿ� �����ϰ� �� ������ ����ϼ���.

	//2. ������ �Լ��� �۵��ϵ��� �Լ��� ���弼��
	// ���ø��� ����ϼ���.

	auto longestString = my_max_element(v.begin(), v.end(), [](string s1, string s2) { return s1.size() < s2.size(); });
	cout << *longestString << endl;

	//3. ���Ͽ��� ���� ���� ������ �ܾ� 5���� ����ϼ���.
	map<int, string> m2;
	for (auto i : m)
	{
		m2[i.second] = i.first;
	}

	auto a = m2.rbegin();
	for (int i = 0; i < 5; ++i)
	{
		cout << a->first << " - " << a->second << endl;
		++a;
	}
	cout << endl;


	//4.�ܾ���� ������������ ���������� the ������ �ִ� �ܾ ����ϼ���. theft

	// ���� �˰����� ����ϸ� �ȵ˴ϴ�.

	auto the = m.find("the");
	++the;
	cout << the->first << endl;



	//5. ������ �ڵ尡 ���ư����� �Լ��� ���弼��. ������ ������ �˻��ϼ���.

	ofstream out{ "�׳� �ܾ��.txt" };


	my_copy(v.begin(), v.end(), ostream_iterator<string>(out, "\n"));

}