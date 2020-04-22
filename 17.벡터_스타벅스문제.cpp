#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

string coffeeArray[8] = { "콜드브루", "아메리카노","카페모카","아이스티","에스프레소","프라푸치노","블렌디드","피지오" };

uniform_int_distribution<> charuid('a', 'z');
uniform_int_distribution<> lenuid(10, 20);
uniform_int_distribution<> coffeeNumuid(3, 10);
uniform_int_distribution<> coffeeArrayuid(0, 7);

default_random_engine dre;

class Customer
{
	string nickname;
	int orderNum = -1;
	vector<string> orderlist;
public:
	Customer() :nickname{ "오류" }, orderNum{ -99999 } {}

	Customer(int &orderCount) :orderNum(++orderCount)
	{
		int namelen = lenuid(dre);
		for (int i = 0; i < namelen; ++i)
		{
			nickname += charuid(dre);
		}
		int orderlen = coffeeNumuid(dre);
		orderlist.reserve(orderlen);
		for (int i = 0; i < orderlen; ++i)
		{
			orderlist.emplace_back(coffeeArray[coffeeArrayuid(dre)]);
		}
	}

	Customer(string s, int i, vector<string> v)
	{
		nickname = s;
		orderNum = i;
		orderlist = v;
	}

	void show()		//show함수 구현
	{
		cout << nickname << " " << orderNum << " " << orderlist.size()<<" ";
		for (const string& str : orderlist)
		{
			cout << str << " ";
		}
		cout << endl;
	}

	string getName() const {
		return nickname;
	}

	int getOrderNumber() const {
		return orderNum;
	}

	vector<string>& getOrderlist() {
		return orderlist;
	}
	int getSize() const {
		return orderlist.size();
	}

};

void makeVIPcustomer(vector<Customer>& a, vector<Customer>& b)
{
	for (auto i = a.begin(); i != a.end();)
	{
		if (i->getOrderNumber() % 10 == 7)
		{
			b.push_back(*i);
			i = a.erase(i);
		}
		else ++i;
	}
}

int main()
{
	int ordercount = 0;
	vector<Customer> customerlist;

	ofstream out("CustomerManagement.star");

	for (int i = 0; i < 1000; ++i)
	{
		Customer c = ordercount;
		out << c.getName() << " " << c.getOrderNumber() << " " << c.getOrderlist().size()
			<< " ";
		for (const string& str : c.getOrderlist())
		{
			out << str<< " ";
		}
		out << endl;
	}

	ifstream in("CustomerManagement.star");
	for (int i = 0; i < 1000; ++i)
	{
		string s;
		int n;
		int n2;
		vector<string> v;

		in >> s >> n >> n2;
		for (int j = 0; j < n2; ++j)
		{
			string s2;
			in >> s2;
			v.push_back(s2);
		}
		Customer a = { s,n,v };
		customerlist.push_back(a);

	}
	sort(customerlist.begin(), customerlist.end(), [](Customer a, Customer b) {		//커피 갯수대로 오름차순
		return a.getSize() < b.getSize();
	});
	
		for (auto i = customerlist.begin(); i != customerlist.end();)			//닉네임 'f'로 시작 고객 삭제
		{
			if (i->getName()[0] == (char)'f')
			{
				i = customerlist.erase(i);
			}
			else ++i;
		}


	vector<Customer> VIPlist;
	makeVIPcustomer(customerlist, VIPlist);

	for (Customer& str : VIPlist)
	{
		str.show();
	}
}