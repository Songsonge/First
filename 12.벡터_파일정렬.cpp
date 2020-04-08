#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	ifstream in("20200408.txt");

	vector<string> v{ istream_iterator<string>(in), istream_iterator<string>() };

	sort(v.begin(), v.end());

	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));

	int mycount = count_if(v.begin(), v.end(), [](string a) { return *a.begin() == 'w'; });
	std::cout << "myvector contains " << mycount << " odd values.\n";

}