#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

enum Tier { common, rare, epic, legend };
string NameofTier[4]{ "커먼", "레어", "에픽","레전드" };	//3번. 추가

uniform_int_distribution<> nameuid(30, 80);
uniform_int_distribution<> hpuid(-50, 200);
uniform_int_distribution<> tieruid(common, epic);
uniform_int_distribution<> charuid('a', 'z');
default_random_engine dre;



class Cookie
{
	string name;
	int hp;
	bool isdie = false;
	Tier tier;

public:

	Cookie()
	{
		for (int i = 0; i < nameuid(dre); ++i)
		{
			name += charuid(dre);
		}

		hp = hpuid(dre);

		tier = Tier(tieruid(dre)); // 초록색 밑줄이 나타날 수도 있지만 무시하고 지나가자.
	}

	void show()
	{
		if (!isdie)
		{
			cout<<left << setw(80) << name << " " << setw(4) << hp << " ";
			showtier();
			return;
		}

		cout << "이 쿠키는 죽었습니다." << endl;
	}

	void showtier()
	{
		cout << NameofTier[tier] << endl;
	}

	void setTier(int n)
	{
		tier = Tier(n);
	}

	string getName() const {
		return name;
	}

	int getHp() const {
		return hp;
	}

	int getTier() const {
		return tier;
	}

	void setName(string s)
	{
		name = s;
	}

	void setHp(int n)
	{
		hp = n;
	}
	void setDie(bool b)
	{
		isdie = b;
	}

};


int main()
{
	Cookie* data = new Cookie[1'0000];	//쿠키 만 개 만듦
	
	ofstream out("쿠키 30000개.data");

	for (int i = 0; i < 10000; ++i)
	{
		out << data[i].getName() << " " << data[i].getHp() << " " << data[i].getTier() << endl;
	}
	
	Cookie *data2 = new Cookie[10000];
	ifstream in("쿠키 30000개.data");


	for (int i = 0; i < 10000; ++i)		//3. 정수->한글 출력
	{
		string s;
		int a;
		int b;
		in >> s;
		in >> a;
		in >> b;

		data2[i].setName(s);
		data2[i].setHp(a);
		data2[i].setTier(b);

	}

	sort(&data2[0], &data2[1'0000], [](Cookie a, Cookie b) {	//4. 오름차순
		return a.getHp() < b.getHp();
	});

	for (int i = 0; i < 10000; ++i)	//5. 쿠키 다 죽이기
	{

		if (data2[i].getHp() <= 0)
		{
			data2[i].setDie(true);
		}
			//data2[i].show();

	}

	short arr[26] = {};		//6번. 뒤지게어려운 문제
	//for (int i= 0; i < 10000; ++i)
	//{
	//	++alpha[data2[i].getName()[0]-'a'];
	//}

	//for (int i = 0; i < 26; ++i)
	//{
	//	cout<<(char)(i+'a')<<" " << alpha[i] << endl;
	//}

	for (int i = 0; i < 10000; ++i)
	{
		string s = data2[i].getName();
		auto p = s.begin();
		int q = *p - 'a';
		++arr[q];
	}

	for (int i = 0; i < 10000; ++i)
	{
		string s = data2[i].getName();
		auto p = s.rbegin();
		if (*p == 'z')
		{
			data2[i].setTier(3);
		}
		data2[i].show();
	}

	//문제를 해결하는데 필요한 코드를 추가해야한다면 추가한뒤 주석으로 추가한 코드에 대한 설명을 덧붙여야 한다.

	//문제 1. 쿠키 만개를 만들어서 Cookie.data 파일에 저장하라

	//문제 2. 파일 Cookie.data 를 읽어서 자료구조에 저장하라.

	//문제 3. showtier()를 이용해서 출력했더니 마음에 들지 않는다. tier가 정수로 출력된다. tier를 한글로 출력하자
	// common이면 커먼, rare면 레어, epic이면 에픽, legend면 레전드
	// 단 조건문을 사용하지 않는다.

	//문제 4. qsort 함수를 이용 체력 오름차순으로 정렬하라.

	//문제 5. 체력이 0 이하인 쿠키는 다 죽여버리자.

	//문제 6. 밑의 배열을 이용하여 이름마다 각각의 단어로 시작하는 이름들의 갯수를 구하고 출력하라.
	// a - 몇개
	// b - 몇개
	// ...
	// 예를들어 abcdef가 이름이라면 a로 시작하므로 a로 시작하는 이름의 갯수가 하나 추가된다.
	// 단 문제 5번을 해결하는데 60바이트 이상을 사용해선 안된다.

	//문제 7. name의 맨 뒷글자가 Z라면 그 쿠키의 등급을 레전드로 바꾼다.

}


