#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

uniform_int_distribution<> alphauid('a', 'z');
uniform_int_distribution<> lenuid(30, 80);
uniform_int_distribution<> serialuid(1'0000'0000, 2'0000'0000);
default_random_engine dre;

class Product
{
	string name;
	int serialNumber;
public:
	Product()
	{
		int len = lenuid(dre);
		for (int i = 0; i < len; ++i)
		{
			name += alphauid(dre);
			serialNumber = serialuid(dre);
		}
	}
	string getName() const {
		return name;
	}
	int getNumber() const {
		return serialNumber;
	}
};

template<class T, int n>
class Daiso
{
	T* data;
	int size;
	int capacity;

public:

	Daiso() {
		data = new T[n];
		size = 0;
		capacity = 50;
	}


	bool push_back(const T& p)
	{
		if (capacity == size)
		{
			T* vc = new T[capacity * 2];
			for (int i = 0; i < size; ++i)
			{
				vc[i] = data[i];
			}
			capacity *= 2;
			delete[] data;
			data = vc;

			data[size++] = p;
		}
		else {
			data[size++] = p;
		}
			//원소를 하나 추가할 때 마다 size가 1씩 증가한다.	
			return true;
		
	}


	void show()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << setw(80) << left << data[i].getName() << data[i].getNumber()<< " "<<i<< endl;
		}
			//배열 안의 모든 원소를 출력한다. (이름, 시리얼넘버)

	}


	void PrintWithNumber(int n)
	{
		for (int i = 0; i < size; ++i)
		{
			if (data[i].getNumber() == n)
			{
				cout << "찾았다! " << data[i].getNumber() << endl;
			}
		}
	}

	int getSize() const {
		return size;
	}
	T* getData() const {
		return data;
	}

};
int main()
{
	//멤버함수는 얼마든지 추가가 가능하지만 멤버변수는 수정해서는 안된다.
	Daiso<Product, 50> anyang; // n만큼의 배열을 동적할당하자 size = 0, capacity = 50
							   //1. push_back과 show를 수정하자
	for (int i = 0; i < 60; ++i)
	{
		Product a;
		anyang.push_back(a); //하나 집어넣을때마다 size 1씩 증가한다
	}
	anyang.show(); //잘 출력되도록 수정하자
				   //2. 배열이 꽉찼다. 더 큰배열이 필요하다. 아래의 코드가 문제없이 돌아가도록 push_back을 수정하자
				   // 박스에 자리가 없다면 새로운 박스에 옮겨담으면 될 것 같다.
	Product a;
	anyang.push_back(a);

	anyang.show();
	//3. 시리얼 넘버가 171156935인 제품의 정보를 출력하자
	anyang.PrintWithNumber(1'0165'3157); //들어있는 아무 숫자로 변경해도 좋다.

	ofstream out("DaisoProductList.daiso");			 //4. 다이소 a의 모든 제품을 "DaisoProductList.daiso" 파일에 저장하자

	for (int i = 0; i < anyang.getSize(); ++i)
	{
		out << anyang.getData()[i].getName()<<" "<<anyang.getData()[i].getNumber() << endl;
	}

}

