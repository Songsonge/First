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

	//============================1번문제: e 제거==================================

	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };

	//for (auto i = v.begin(); i != v.end();)
	//{
	//	if (*i == 'e')
	//	{
	//		i = v.erase(i);
	//	}
	//	else ++i;
	//}

	//ofstream out("STL Wiki에서 e제거.txt");
	//copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));


	//vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };

	//===========================2번문제: 단어 개수=================================

	//cout << "STL WiKi.txt에 있는 단어 개수: " << v.size() << endl;


	//===========================3번문제:단어 뒤집기=================================

	//for (string str : v)
	//{
	//	reverse(str.begin(), str.end());
	//	cout << str <<" ";
	//}


	//=========================4번문제:오름 차순 정렬================================

	//sort(v.begin(), v.end(), [](string a, string b) {
	//	return a < b;
	//});

	//for (string str : v)
	//{
	//	cout << str <<" ";
	//}


	//=======================5번문제:길이 오름 차순 정렬=============================
	//sort(v.begin(), v.end(), [](string a, string b) {
	//	return a.length() < b.length();
	//});


	//========================6번문제:the 개수 세기=================================

	//int i = count_if(v.begin(), v.end(), [](string a) {
	//	return a == "the";
	//});
	//cout << "the의 개수는 " << i << "개 입니다." << endl;


	//=========================7번문제:5글자 단어 저장===============================

	//ofstream out("STL Wiki에서 5글자로 된 단어.txt");
	//copy_if(v.begin(), v.end(), ostream_iterator<string>(out," "), [](string a) {
	//	return a.length() == 5; });

	//=========================도전문제:단어 뒤집기===============================
	
	ofstream out("STL Wiki 단어 역순.txt");
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