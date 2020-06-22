#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

void makeData();

string fname{ "����1.txt" };

int main()
{
	makeData();
//=============================================================================
// 1�� ����: "����.txt"�� �ִ� �ܾ�(�������� �и��� ���ĺ�)�� ����(������������ ����, �ߺ��ܾ� ����)�� ������� �Ѵ�.
//"����1.txt"�� �о� ������ ����� ����� "����.txt"�� �����϶�
//������ �ִ� �ܾ� ���� ����ϰ� ��� ����� �������� �����.
//=============================================================================

	ifstream in("����1.txt");
	set<string> words{ istream_iterator<string>(in),istream_iterator<string>() };

	ofstream out("����.txt");
	copy(words.begin(), words.end(), ostream_iterator<string>(out, "\n"));

	cout <<"1�� ��: "<< words.size() << endl;						
	//for (auto i : words)
	//{
	//	cout << i << endl;
	//}


	//=============================================================================
	//2. ������ "key"��� �ܾ �ִ��� �˰� �ʹ�.
	//�ܾ ������ �� ��° �ܾ����� ����϶�. ������ "���� �ܾ�"��� ���
	//=============================================================================

	auto iter = words.find("key");
	int grade = distance(words.begin(), iter);
	if(iter!=words.end())
		cout << "2�� ��: " << grade << "��°" << endl;
	else
		cout << "���� �ܾ�" << endl;

	//=============================================================================
	// 3. �������� ������ ���ĺ����� �����ϴ� �ܾ��� ������ ����϶�.
	// a - �� ��
	// ...
	// z - �� ��
	//=============================================================================

	for (char i = 'a'; i <= 'z'; ++i)
	{
		string s;		//set�� string���� ����Ǿ������ϱ� string ����
		string s2;
		s+= i;			// s=a�������
		auto begin = words.find(s);
		s2 +=++i;		// s=b�������
		auto end = words.find(s2);
		--i;					//����ġ

		//char c = i;
		//char c2 = i + 1;
		//auto begin = m.find(string(c));
		//auto end = m.find(string(c2));
		//cout << "i : " << distance(begin, end) << endl;

		int num = distance(begin, end); 
		cout << i << ": " << num << endl;
	}


	//=============================================================================
	// 4. "����.txt"�� �ִ� �ܾ�� �� "�ȷ� Ȩ���� ����.txt"�� �ִ� �ܾ�(�ߺ��ܾ�) �˰� �ʹ�.
	// �� �ܾ�餷�� ���� "�ܾ�鿡 �ִ� �ܾ�.txt"�� �����϶�
	// "�ܾ�鿡 �ִ� �ܾ�.txt"�� �ִ� �ܾ� ���� ����϶�.
	//=============================================================================

	ifstream in1("�ȷ� Ȩ���� ����.txt");
	set<string> sherlock{ istream_iterator<string>(in1),istream_iterator<string>() };

	ofstream out1("�ܾ�鿡 �ִ� �ܾ�.txt");

	int n = 0;
	for (auto& i : words)
	{
		if (sherlock.find(i) != sherlock.end()) {
			out1 << i << endl;
			++n;
		}

	}
	cout << "4�� ��: " << n << "��" << endl;

}




void makeData()
{
	default_random_engine dre;
	uniform_int_distribution<> alpha{ 'a','z' };
	uniform_int_distribution<>len{ 1,30 };

	ofstream out{ fname };

	for (int i = 0; i < 20'0000; ++i)
	{
		string s;
		for (int j = 0; j < len(dre); ++j)
			s += alpha(dre);
		out << s << " \n";
	}
	cout << "20�� �ܾ " << fname << "�� ����Ͽ���" << endl;
}