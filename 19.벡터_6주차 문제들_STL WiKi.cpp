#include <iostream>
#include <fstream>
#include <string>
#include "String.h"
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{	
	ifstream in("STL WiKi.txt");

	//============================1������: e ����==================================

	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };

	//for (auto i = v.begin(); i != v.end();)
	//{
	//	if (*i == 'e')
	//	{
	//		i = v.erase(i);
	//	}
	//	else ++i;
	//}

	//ofstream out("STL Wiki���� e����.txt");
	//copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));


	//vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };

	//===========================2������: �ܾ� ����=================================

	//cout << "STL WiKi.txt�� �ִ� �ܾ� ����: " << v.size() << endl;


	//===========================3������:�ܾ� ������=================================

	//for (string str : v)
	//{
	//	reverse(str.begin(), str.end());
	//	cout << str <<" ";
	//}


	//=========================4������:���� ���� ����================================

	//sort(v.begin(), v.end(), [](string a, string b) {
	//	return a < b;
	//});

	//for (string str : v)
	//{
	//	cout << str <<" ";
	//}


	//=======================5������:���� ���� ���� ����=============================
	//sort(v.begin(), v.end(), [](string a, string b) {
	//	return a.length() < b.length();
	//});


	//========================6������:the ���� ����=================================

	//int i = count_if(v.begin(), v.end(), [](string a) {
	//	return a == "the";
	//});
	//cout << "the�� ������ " << i << "�� �Դϴ�." << endl;


	//=========================7������:5���� �ܾ� ����===============================

	//ofstream out("STL Wiki���� 5���ڷ� �� �ܾ�.txt");
	//copy_if(v.begin(), v.end(), ostream_iterator<string>(out," "), [](string a) {
	//	return a.length() == 5; });

	//=========================��������:�ܾ� ������===============================
	
	ofstream out("STL Wiki �ܾ� ����.txt");
	string s;

	for (char c : v)
	{
		if (c == ' ' || c == '\n')
		{			
			reverse(s.begin(), s.end());
			out << s;
			out << c;
			s.clear();
		}
		else
		{
			s += c;
		}
	}

}