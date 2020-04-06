#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

enum Tier { common, rare, epic, legend };
string NameofTier[4]{ "Ŀ��", "����", "����","������" };	//3��. �߰�

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

		tier = Tier(tieruid(dre)); // �ʷϻ� ������ ��Ÿ�� ���� ������ �����ϰ� ��������.
	}

	void show()
	{
		if (!isdie)
		{
			cout<<left << setw(80) << name << " " << setw(4) << hp << " ";
			showtier();
			return;
		}

		cout << "�� ��Ű�� �׾����ϴ�." << endl;
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
	Cookie* data = new Cookie[1'0000];	//��Ű �� �� ����
	
	ofstream out("��Ű 30000��.data");

	for (int i = 0; i < 10000; ++i)
	{
		out << data[i].getName() << " " << data[i].getHp() << " " << data[i].getTier() << endl;
	}
	
	Cookie *data2 = new Cookie[10000];
	ifstream in("��Ű 30000��.data");


	for (int i = 0; i < 10000; ++i)		//3. ����->�ѱ� ���
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

	sort(&data2[0], &data2[1'0000], [](Cookie a, Cookie b) {	//4. ��������
		return a.getHp() < b.getHp();
	});

	for (int i = 0; i < 10000; ++i)	//5. ��Ű �� ���̱�
	{

		if (data2[i].getHp() <= 0)
		{
			data2[i].setDie(true);
		}
			//data2[i].show();

	}

	short arr[26] = {};		//6��. �����Ծ���� ����
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

	//������ �ذ��ϴµ� �ʿ��� �ڵ带 �߰��ؾ��Ѵٸ� �߰��ѵ� �ּ����� �߰��� �ڵ忡 ���� ������ ���ٿ��� �Ѵ�.

	//���� 1. ��Ű ������ ���� Cookie.data ���Ͽ� �����϶�

	//���� 2. ���� Cookie.data �� �о �ڷᱸ���� �����϶�.

	//���� 3. showtier()�� �̿��ؼ� ����ߴ��� ������ ���� �ʴ´�. tier�� ������ ��µȴ�. tier�� �ѱ۷� �������
	// common�̸� Ŀ��, rare�� ����, epic�̸� ����, legend�� ������
	// �� ���ǹ��� ������� �ʴ´�.

	//���� 4. qsort �Լ��� �̿� ü�� ������������ �����϶�.

	//���� 5. ü���� 0 ������ ��Ű�� �� �׿�������.

	//���� 6. ���� �迭�� �̿��Ͽ� �̸����� ������ �ܾ�� �����ϴ� �̸����� ������ ���ϰ� ����϶�.
	// a - �
	// b - �
	// ...
	// ������� abcdef�� �̸��̶�� a�� �����ϹǷ� a�� �����ϴ� �̸��� ������ �ϳ� �߰��ȴ�.
	// �� ���� 5���� �ذ��ϴµ� 60����Ʈ �̻��� ����ؼ� �ȵȴ�.

	//���� 7. name�� �� �ޱ��ڰ� Z��� �� ��Ű�� ����� ������� �ٲ۴�.

}


