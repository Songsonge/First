#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

template <class T,class T2>
T my_max_element(T first, T last, T2 r )
{
	T largest = first;

	while (++first != last)
		if (r(*largest,*first)) 
			largest = first;
	return largest;
}

template<class InputIterator, class OutputIterator>
OutputIterator my_copy(InputIterator first, InputIterator last, OutputIterator result)
{
	while (first != last) {
		*result = *first;
		++result; ++first;
	}
	return result;
}


int main()

{
	ifstream in("셜록 홈즈의 모험.txt");

	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
	cout << "1번. 개수: " << v.size() << endl;

	map<string, int> m;
	for (auto p : v)
	{
		m[p]++;
	}

	//1. 주어진 파일의 모든 단어를 컨테이너에 저장하고 그 개수를 출력하세요.

	//2. 다음의 함수가 작동하도록 함수를 만드세요
	// 템플릿을 사용하세요.

	auto longestString = my_max_element(v.begin(), v.end(), [](string s1, string s2) { return s1.size() < s2.size(); });
	cout << *longestString << endl;

	//3. 파일에서 가장 많이 등장한 단어 5개를 출력하세요.
	map<int, string> m2;
	for (auto i : m)
	{
		m2[i.second] = i.first;
	}

	auto a = m2.rbegin();
	for (int i = 0; i < 5; ++i)
	{
		cout << a->first << " - " << a->second << endl;
		++a;
	}
	cout << endl;


	//4.단어들을 오름차순으로 정렬했을때 the 다음에 있는 단어를 출력하세요. theft

	// 선형 알고리즘은 사용하면 안됩니다.

	auto the = m.find("the");
	++the;
	cout << the->first << endl;



	//5. 다음의 코드가 돌아가도록 함수를 만드세요. 구글을 열심히 검색하세요.

	ofstream out{ "그냥 단어들.txt" };


	my_copy(v.begin(), v.end(), ostream_iterator<string>(out, "\n"));

}