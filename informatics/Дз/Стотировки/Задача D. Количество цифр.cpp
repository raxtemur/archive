#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> Basic(9);

int main() 
{
	int a;
	cin >> a;
	while (a != 0)
	{
		Basic[a - 1]++;
		cin >> a;
	}
	copy(Basic.begin(), Basic.end(), ostream_iterator<int>(cout, " "));
}