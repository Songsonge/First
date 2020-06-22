#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
#include <set>
#include <map>

using namespace std;

int main()
{
    ifstream in("셜록 홈즈의 모험.txt");


    set<string> words = { istream_iterator<string>(in),istream_iterator<string>() };

    multimap<string, string> m;

    for (auto str : words)
    {
        string temps = str;
        sort(temps.begin(), temps.end());
        m.emplace(temps, str);
    }

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