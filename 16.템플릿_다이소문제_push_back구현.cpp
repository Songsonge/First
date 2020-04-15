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
			//���Ҹ� �ϳ� �߰��� �� ���� size�� 1�� �����Ѵ�.	
			return true;
		
	}


	void show()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << setw(80) << left << data[i].getName() << data[i].getNumber()<< " "<<i<< endl;
		}
			//�迭 ���� ��� ���Ҹ� ����Ѵ�. (�̸�, �ø���ѹ�)

	}


	void PrintWithNumber(int n)
	{
		for (int i = 0; i < size; ++i)
		{
			if (data[i].getNumber() == n)
			{
				cout << "ã�Ҵ�! " << data[i].getNumber() << endl;
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
	//����Լ��� �󸶵��� �߰��� ���������� ��������� �����ؼ��� �ȵȴ�.
	Daiso<Product, 50> anyang; // n��ŭ�� �迭�� �����Ҵ����� size = 0, capacity = 50
							   //1. push_back�� show�� ��������
	for (int i = 0; i < 60; ++i)
	{
		Product a;
		anyang.push_back(a); //�ϳ� ������������� size 1�� �����Ѵ�
	}
	anyang.show(); //�� ��µǵ��� ��������
				   //2. �迭�� ��á��. �� ū�迭�� �ʿ��ϴ�. �Ʒ��� �ڵ尡 �������� ���ư����� push_back�� ��������
				   // �ڽ��� �ڸ��� ���ٸ� ���ο� �ڽ��� �Űܴ����� �� �� ����.
	Product a;
	anyang.push_back(a);

	anyang.show();
	//3. �ø��� �ѹ��� 171156935�� ��ǰ�� ������ �������
	anyang.PrintWithNumber(1'0165'3157); //����ִ� �ƹ� ���ڷ� �����ص� ����.

	ofstream out("DaisoProductList.daiso");			 //4. ���̼� a�� ��� ��ǰ�� "DaisoProductList.daiso" ���Ͽ� ��������

	for (int i = 0; i < anyang.getSize(); ++i)
	{
		out << anyang.getData()[i].getName()<<" "<<anyang.getData()[i].getNumber() << endl;
	}

}

