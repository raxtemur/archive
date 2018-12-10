#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> Arr;

void input()
{
	int a;
	while (cin >> a)
	{
		Arr.push_back(a);
	}
}

void BubbleSort()
{
	for (int k = 0; k < Arr.size() - 1; k++)
	{
		for (int i = Arr.size() - 1; i > 0; i--)
		{
			if (Arr[i] > Arr[i - 1]) { swap(Arr[i], Arr[i - 1]); }
		}
	}
}

void print()
{
	for (int i = 0; i < Arr.size(); i++)
	{
		cout << Arr[i] << " ";
	}
}

int main()
{
	input();
	BubbleSort();
	print();
}