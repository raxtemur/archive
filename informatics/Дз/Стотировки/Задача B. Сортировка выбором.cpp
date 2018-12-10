#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> Arr;
int Great[2]; // Great[0] - наибольшее значение, Great[1] - порядковый номер этого значения

void input()
{
	int a;
	while (cin >> a)
	{
		Arr.push_back(a);
	}
}

void SelectionSort()
{
	for (int k = 0; k < Arr.size() - 1; k++)
	{
		Great[0] = Arr[k];
		Great[1] = k;
		for (int i = k + 1; i < Arr.size(); i++)
		{
			if (Arr[i] > Great[0]) { Great[0] = Arr[i]; Great[1] = i; }
		}
		if (Great[0] > Arr[k]) { swap(Arr[k], Arr[Great[1]]); }
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
	SelectionSort();
	print();
}