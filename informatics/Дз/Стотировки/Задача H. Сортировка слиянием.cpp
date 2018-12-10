#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vecArr, Buffer;
vector<int>::iterator it, ItToErase, ItToInsert;

void input()
{
	int a;
	while (fin >> a)
	{
		vecArr.push_back(a);
	}
}


void print(vector<int> vecArray)
{
	for (int i = 0; i < vecArray.size(); i++)
	{
		fout << vecArray[i] << " ";
	}
}

void Sliv(int L, int R)
{
	int x = 0;
	int a = L, b = (L + R) / 2 + 1;
	while ((a < (L + R) / 2 + 1) && (b < R + 1))
	{
		if (vecArr[a] < vecArr[b]) { Buffer.push_back(vecArr[a]); a++; }
		else { Buffer.push_back(vecArr[b]); b++; }
		x++;
	}
	if (a < (L + R) / 2 + 1) { for (size_t i = a; i < (L + R) / 2 + 1; i++) { Buffer.push_back(vecArr[i]); } }
	if (b < R + 1)			 { for (size_t i = b; i < R + 1; i++)			{ Buffer.push_back(vecArr[i]); } }
	for (size_t i = L, x = 0; i < R + 1; i++, x++) { vecArr[i] = Buffer[x]; }
	Buffer.clear();
}

void Sort(int L, int R)
{
	if (L != R) 
	{
		Sort(L, (L + R) / 2);
		Sort((L + R) / 2 + 1, R);
		Sliv(L, R);
	}
}

int main()
{
	int N;
	fin >> N;
	input();
	Sort(0, N - 1);
	print(vecArr);
}