#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <fstream>
using namespace std;
int gid = 0;

default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);

class Dog {
	string name; // �̸� - 15 ���ڱ����� ���
	int age; // ���� 
	int id; // ���� �� �����Ǵ� ������ ���ڷ� �� id
public:
	Dog() :id(++gid)
	{
		int len = uidNameLen(dre);
		for (int i = 0; i < len; ++i)
			name += uidName(dre);
		age = uidAge(dre);
	}

	Dog(string name, int age) : name{ name }, age{ age }, id(++gid)
	{
	}

	string getName() const
	{
		return name;
	}

	friend ostream& operator<<(ostream&, const Dog&);
};


ostream& operator<<(ostream& os, const Dog& d)
{
	os << setw(15) << d.name << " " << setw(5) << d.age << " " << setw(5) << d.id;
	return os;
}


int main()
{
	ofstream out("Dog ������", ios::binary);

	for (int i = 0; i < 1'0000; ++i)
	{
		Dog d;
		out.write((char*)&d, sizeof(Dog));
	}

	Dog* data = new Dog[1'0000];

	ifstream in("Dog ������", ios::binary);

	in.read((char*)data, 10000 * sizeof(Dog)); // char*�� �ǹ�: 1����Ʈ�� ��������



	sort(&data[0], &data[10000], [](Dog a, Dog b) {
		return a.getName() < b.getName();
	});

	cout << data[0] << endl;
	cout << data[9999] << endl;

}