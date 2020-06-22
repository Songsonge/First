#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

int main()
{
	ifstream in("셜록 홈즈의 모험.txt");
    vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };

    cout << v.size() << "단어를 읽었습니다" << endl;



    multimap<string, string> m;


    for (auto& p : v)
    {
        for (int i = 0; i < p.size(); ++i)
        {
            p[i] = tolower(p[i]);
        }
    }
    //====================================================
    for (string& str : v)
    {
        string temps = str;
        sort(temps.begin(), temps.end());
        auto p = m.equal_range(temps);
        bool a = true;
        for (auto iter = p.first; iter != p.second; ++iter)
        {
            if (iter->second == str)
            {
                a = false;
                break;
            }
        }
        
        if (a)
        {
            m.emplace(temps, str);
        }
    }

    //====================================================


    //for (auto i : v)
    //{
    //    string s;
    //    s = i;
    //    sort(s.begin(), s.end(), [](const char& a, const char& b) {
    //        return a < b; });
    //    m.emplace(s,i);
    //}
    ofstream out("애너그램 정렬한거.txt");

    for (auto iter = m.begin(); iter != m.end(); ++iter)
    {
        auto begin = adjacent_find(iter, m.end(), [](const pair<string, string>& a, const pair<string, string>& b) {
            return a.first == b.first;
            });
        auto findbegin = begin;

        if (begin != m.end())
        {
            auto end = find_if_not(++findbegin, m.end(), [begin](const pair<string, string>& a)
                {
                    return a.first == begin->first;
                });
            iter = end;
            for (auto i = begin; i != end; ++i)
            {
                out << i->first << " " << i->second << endl;
            }
        }

    }


}