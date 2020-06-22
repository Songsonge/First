#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

// ���� Ŭ���� : ���� �ִ� Ŭ������ ��¦ ��Ʋ� �� ��Ĵ�� ������
struct PS : pair<string, string> {
    PS(string s) : pair(s, s) {
        sort(first.begin(), first.end());
    }
};

ostream& operator<<(ostream& os, const PS& p) {
    os << p.second;
    return os;
}

int main()
{
    ifstream in("�ܾ��.txt");
    string s;
    vector<PS> v;
    v.reserve(30'0000);

    while (in >> s)
        v.emplace_back(s);
    //cout << v.size() << "�ܾ �о����ϴ�" << endl;

    // �� �ܾ� 10��
    //nth_element(v.begin(), v.begin() + 10, v.end(), [](const PS& a, const PS& b) { return a.first.length() > b.first.length(); });
    //for (int i = 0; i < 10; ++i)
    //   cout << v[i].second << endl;

    // �ܾ��� ���� first �������� �����Ѵ�
    sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
        return a.first < b.first; });

    //for (int i = 120000; i < 121000; ++i) {
    //   //cout << v[i].first << "\t" << v[i].second << endl;
    //   auto [���Ĵܾ�, �����ܾ�] = v[i];
    //   cout << ���Ĵܾ� << '\t\t' << �����ܾ� << endl;
    //}

    // ������ �ٸ� �������� �� �� �ֵ��� ������ �籸���Ѵ�
    // �ܾ - [�����Ѵܾ�, �����ܾ�] ������ �����

    cout << "---------------------" << endl;
    cout << "�ֳʱ׷��� ã�Ƶ帳�ϴ�" << endl;
    cout << "---------------------" << endl;

    int cnt = 0;
    auto i = v.begin();

    // [����] ã�� �ֳʱ׷����� ��� "�ֳʱ׷� ��.txt"�� ����϶�
    ofstream out1("�ֳʱ׷� ��.txt");
    vector<list<string>> vl;
    vl.reserve(31000);

    while (true) {
        /*cout << "�ܾ �Է��ϼ���: ";
        string word;
        cin >> word;

        sort(word.begin(), word.end());
        auto [ó��, ������] = equal_range(v.begin(), v.end(), word, [](const PS& a, const PS& b) { return a.first < b.first; });

        if (ó�� == ������) {
           cout << "���� �ܾ��Դϴ�" << endl;
           continue;
        }
        for (auto i = ó��; i < ������; ++i)
           cout << i->second << "\t";
        cout << endl;*/

        auto j = adjacent_find(i, v.end(), [](const PS& a, const PS& b) { return a.first == b.first; });
        if (j == v.end())
            break;

        auto k = find_if_not(j + 1, v.end(), [j](const PS& a) { return a.first == j->first; });

        // ����[j, k)�� anagram �����̴�
        // cout -> out1
        out1 << "[" << ++cnt << "] ";
        copy(j, k, ostream_iterator<PS>(out1, " "));
        out1 << endl;

        list<string> l;
        for (auto x = j; x < k; ++x)
            l.push_back(x->second);
        vl.push_back(l);

        i = k;
    }

    // [����] ��� ���� ������ ���� ���� �� ���� ��� �����ؼ� "�ֳʱ׷� ���� ��������.txt" ���Ͽ� �����϶�
    ofstream out2("�ֳʱ׷� ���� ��������.txt");

    sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b) {
        return a.size() > b.size();
        });

    // cout -> out2
    for (int i = 0; i < vl.size(); ++i) {
        out2 << "[" << i + 1 << "] (" << vl[i].size() << ") - ";
        copy(vl[i].begin(), vl[i].end(), ostream_iterator<string>(out2, "\t"));
        out2 << endl;
    }
    // �ٸ� ���
    /*for (const list<string>& l : vl) {
       out2 << l.size() << " - ";
       for (const string& s : l)
          out2 << s << "  ";
       out2 << endl;
    }*/
}