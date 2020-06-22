#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

// 서브 클래싱 : 원래 있던 클래스를 살짝 비틀어서 내 방식대로 만들자
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
    ifstream in("단어들.txt");
    string s;
    vector<PS> v;
    v.reserve(30'0000);

    while (in >> s)
        v.emplace_back(s);
    //cout << v.size() << "단어를 읽었습니다" << endl;

    // 긴 단어 10개
    //nth_element(v.begin(), v.begin() + 10, v.end(), [](const PS& a, const PS& b) { return a.first.length() > b.first.length(); });
    //for (int i = 0; i < 10; ++i)
    //   cout << v[i].second << endl;

    // 단어의 쌍을 first 기준으로 정렬한다
    sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
        return a.first < b.first; });

    //for (int i = 120000; i < 121000; ++i) {
    //   //cout << v[i].first << "\t" << v[i].second << endl;
    //   auto [정렬단어, 원본단어] = v[i];
    //   cout << 정렬단어 << '\t\t' << 원본단어 << endl;
    //}

    // 문제를 다른 관점으로 볼 수 있도록 사전을 재구성한다
    // 단어를 - [정렬한단어, 원본단어] 쌍으로 만든다

    cout << "---------------------" << endl;
    cout << "애너그램을 찾아드립니다" << endl;
    cout << "---------------------" << endl;

    int cnt = 0;
    auto i = v.begin();

    // [문제] 찾은 애너그램들을 모두 "애너그램 쌍.txt"에 기록하라
    ofstream out1("애너그램 쌍.txt");
    vector<list<string>> vl;
    vl.reserve(31000);

    while (true) {
        /*cout << "단어를 입력하세요: ";
        string word;
        cin >> word;

        sort(word.begin(), word.end());
        auto [처음, 마지막] = equal_range(v.begin(), v.end(), word, [](const PS& a, const PS& b) { return a.first < b.first; });

        if (처음 == 마지막) {
           cout << "없는 단어입니다" << endl;
           continue;
        }
        for (auto i = 처음; i < 마지막; ++i)
           cout << i->second << "\t";
        cout << endl;*/

        auto j = adjacent_find(i, v.end(), [](const PS& a, const PS& b) { return a.first == b.first; });
        if (j == v.end())
            break;

        auto k = find_if_not(j + 1, v.end(), [j](const PS& a) { return a.first == j->first; });

        // 구간[j, k)는 anagram 관계이다
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

    // [문제] 어느 쌍이 개수가 가장 많은 지 순서 대로 정렬해서 "애너그램 개수 내림차순.txt" 파일에 저장하라
    ofstream out2("애너그램 개수 내림차순.txt");

    sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b) {
        return a.size() > b.size();
        });

    // cout -> out2
    for (int i = 0; i < vl.size(); ++i) {
        out2 << "[" << i + 1 << "] (" << vl[i].size() << ") - ";
        copy(vl[i].begin(), vl[i].end(), ostream_iterator<string>(out2, "\t"));
        out2 << endl;
    }
    // 다른 방법
    /*for (const list<string>& l : vl) {
       out2 << l.size() << " - ";
       for (const string& s : l)
          out2 << s << "  ";
       out2 << endl;
    }*/
}