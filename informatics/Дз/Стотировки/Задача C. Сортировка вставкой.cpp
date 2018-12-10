#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

vector<int> Arr;
vector<int>::iterator it, ItToErase, ItToInsert;

void input()
{
	int a;
	while (cin >> a)
	{
		Arr.push_back(a);
	}
}

void InsertionSort(int NumOfEl)
{
	if (NumOfEl > 2) { InsertionSort(NumOfEl - 1); }
	ItToErase = Arr.begin() + (NumOfEl - 1);
	for (int i = 0; i < NumOfEl - 1; i++)
	{
		if (Arr[i] > Arr[NumOfEl - 1]) 
		{
			int ToInsert = Arr[NumOfEl - 1];
			ItToInsert = Arr.begin() + i;
			Arr.erase(ItToErase);
			Arr.insert(ItToInsert, ToInsert);
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
	it = (Arr.begin());
	InsertionSort(Arr.size());
	print();
}