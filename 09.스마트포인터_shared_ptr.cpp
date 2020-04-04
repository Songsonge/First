#include <iostream>

using namespace std;


int id = 0;

// ()�����ڸ� �����ε��� Ŭ����

template<class T>
class Deleter
{
public:
	void operator() (T* p)
	{
		delete[] p;
	}
};


class Dog
{
private:
	int dogId;

public:
	Dog() :dogId(++id)
	{
		cout << "������ -> " << dogId << endl;
	}

	~Dog()
	{
		cout << "�Ҹ��� -> " << dogId << endl;
	}
};

int main()
{
	// ������ ���� �ڵ带 �������� ������
	{
		// ��ü �� �� - �̷��� unique_ptr �� �����ϴ� ���� �� ���� 
		auto dog = make_unique<Dog>();
	}

	shared_ptr<Dog> dogs{ new Dog[3],Deleter<Dog>() };
	shared_ptr<Dog> dogss{ new Dog[3],[](Dog*& p)
	{
		delete[] p;
	} };
}