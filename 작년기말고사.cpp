#include <iostream>
#include <random>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

void makeData();

string fname{ "시험1.txt" };

int main()
{
	makeData();
//=============================================================================
// 1번 문제: "시험.txt"에 있는 단어(공백으로 분리된 알파벳)로 사전(오름차순으로 정렬, 중복단어 없음)을 만드려고 한다.
//"시험1.txt"를 읽어 사전을 만들고 결과를 "사전.txt"로 저장하라
//사전에 있는 단어 수를 출력하고 출력 결과를 답지에도 적어라.
//=============================================================================

	ifstream in("시험1.txt");
	set<string> words{ istream_iterator<string>(in),istream_iterator<string>() };

	ofstream out("사전.txt");
	copy(words.begin(), words.end(), ostream_iterator<string>(out, "\n"));

	cout <<"1번 답: "<< words.size() << endl;						
	//for (auto i : words)
	//{
	//	cout << i << endl;
	//}


	//=============================================================================
	//2. 사전에 "key"라는 단어가 있는지 알고 싶다.
	//단어가 있으면 몇 번째 단어인지 출력하라. 없으면 "없는 단어"라고 출력
	//=============================================================================

	auto iter = words.find("key");
	int grade = distance(words.begin(), iter);
	if(iter!=words.end())
		cout << "2번 답: " << grade << "번째" << endl;
	else
		cout << "없는 단어" << endl;

	//=============================================================================
	// 3. 사전에서 각각의 알파벳으로 시작하는 단어의 개수를 출력하라.
	// a - 몇 개
	// ...
	// z - 몇 개
	//=============================================================================

	for (char i = 'a'; i <= 'z'; ++i)
	{
		string s;		//set이 string으로 저장되어있으니까 string 생성
		string s2;
		s+= i;			// s=a담겨있음
		auto begin = words.find(s);
		s2 +=++i;		// s=b담겨있음
		auto end = words.find(s2);
		--i;					//원위치

		//char c = i;
		//char c2 = i + 1;
		//auto begin = m.find(string(c));
		//auto end = m.find(string(c2));
		//cout << "i : " << distance(begin, end) << endl;

		int num = distance(begin, end); 
		cout << i << ": " << num << endl;
	}


	//=============================================================================
	// 4. "사전.txt"에 있는 단어들 중 "셜록 홈즈의 모험.txt"에 있는 단어(중복단어) 알고 싶다.
	// 이 단어들ㅇ르 따로 "단어들에 있는 단어.txt"에 저장하라
	// "단어들에 있는 단어.txt"에 있는 단어 개수 출력하라.
	//=============================================================================

	ifstream in1("셜록 홈즈의 모험.txt");
	set<string> sherlock{ istream_iterator<string>(in1),istream_iterator<string>() };

	ofstream out1("단어들에 있는 단어.txt");

	int n = 0;
	for (auto& i : words)
	{
		if (sherlock.find(i) != sherlock.end()) {
			out1 << i << endl;
			++n;
		}

	}
	cout << "4번 답: " << n << "개" << endl;

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
	cout << "20만 단어를 " << fname << "에 기록하였다" << endl;
}