#include <iostream>
using namespace std;

class Model
{
private:
	char* data; //���ڸ� ä��������
	int size;


public:
	Model()
	{
		cout << "�⺻�����ڰ� ȣ��Ǿ����ϴ�." << endl;
		data = NULL; // nullptr
		size = 0;
	}

	Model(int n) // n��ŭ char�� �迭�� �����Ҵ� �ϰ� �ҹ��� a�� ä��ÿ�
	{
		cout << "int �����ڰ� ȣ��Ǿ����ϴ�." << endl;
		data = new char[n];
		for (int i = 0; i < n; ++i)
		{
			data[i] = 'a';
		}
		size = n;
	}

	Model(const Model& m)                           //��������� �������� //const = �ٲܼ�����.
	{
		cout << "��������� ȣ��" << endl;
		size = m.size;
		data = new char[m.size];
		memcpy(data, m.data, sizeof(char) * m.size);
	}


	~Model() // �Ҹ��� ȣ��
	{
		cout << "�����ͻ���: " << size << endl;
		delete[] data;
	}

	Model& operator=(const Model& m)
	{
		cout << "�����Ҵ��� ȣ��" << endl;
		size = m.size;
		data = new char[m.size];
		memcpy(data, m.data, sizeof(char) * m.size);
		return *this;
	}

	void print()
	{
		for (int i = 0; i < size; ++i)
		{
			cout << data[i];
		}
		cout << endl;
	}
};

int main()
{
	Model a; //�⺻����
	Model b{ 5 };   //Model b = 1000;
	Model c(b);

	a = c;
}



//������ �����ε� 
// cout << , + , - , <, i++, ++i