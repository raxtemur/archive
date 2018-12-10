#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> Basic(101);

void Numbers()
{
	int a;
	while (cin >> a)
	{
		Basic[a]++;
	}
}

int main() 
{
	Numbers();
	for (int i = 0; i < 101; i++)
	{
		for (int k = 0; k < Basic[i]; k++) { cout << i << " "; }
	}
	Basic.clear();
}