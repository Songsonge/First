#include <iostream> 

using namespace std;

template<class T>
class Array
{
private: 
	T* data;

public:
	Array(T t) {
		data = new T[10];
	}

	int& operator[] (int n)
	{
		return data[n];
	}
};

int main() {
	Array<int> a(10); // ���� 10 ���� ���� �޸� Ȯ��

	for (int i = 0; i < 10; ++i) 
		a[i] = i; // a �� ����

	for (int i = 0; i < 10; ++i) 
		cout << a[i] << ' '; // a ���� �б� cout << endl;
}
