#include <iostream>
using namespace std;

class Model
{
private:
	char* data;
	size_t size;
	//�⺻��
	int n;

public:
	Model() {  }
	Model(int n)
	{
		size = n;
		data = new char[size];

		//github ���������
		//�ݺ���, �迭, ������ ����
		//�����Ҵ� ���� �迭�� ������ �ҹ��ڷ� ä�������ÿ�
		//����ϼ���
		//�׸��� �׷�����


		//4��. ������
		//5��. ��������� (��������,��������)
		//6��. ������,�Ҹ���


	}

	Model(int n, double d)
	{

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
	Model a;
	Model b{ 1000 };


	b.print();

	cout << "�ߵ��ư�" << endl;


}