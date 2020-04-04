#include <iostream>
#include <string>

using namespace std;

template <class T, int n>
class Array
{
private:
	T* data;

public:
	Array()
	{
		data = new T[n];
	}

	T& operator[](int i)
	{
		return data[i];
	}

};

int main() {
	Array<string, 10> a; // string 10 ���� ���� �� �ִ� �ڷᱸ�� a

	for (int i = 0; i < 10; ++i) 
		a[i] = "string"s + to_string(i); // a �� ����

	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl; // a ���� �б�
}