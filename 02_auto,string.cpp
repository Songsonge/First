#include <iostream>
#include <string>

using namespace std;



int main()
{
	string s = "i am C++ master";



	/*auto a = "�ѱ�";
	cout << typeid(a).name() << endl;*/ // auto Ű����


	/*vector<int> v { 1,2,3,4,5,6,7,8,9 };

	for (auto i = v.begin(); i != v.end(); ++i)
	{
	cout << *i;
	}*/

	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i];
	}

	cout << endl;
	for (auto i = s.begin(); i != s.end(); ++i) //�ݺ����� ���� ����
	{
		cout << *i;
	}
	cout << endl;
	for (char d : s)
	{
		cout << d;
	}

	// ���� ���� ���� ��� for��
	// auto Ű����
	// ���������(��������,��������)
	// string Ŭ���� ����


}