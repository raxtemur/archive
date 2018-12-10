#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


vector<bool> Basic;

int dress(int N)
{
	int count = 0;
	for (int i = N; i < 100; i++)
	{
		if (Basic[i]) { count++; i = i + 2; }
	}
	return (count);
}


void Numbers()
{
	int a;
	while (fin >> a) { Basic[a - 1] = true; }
}

int main() 
{
	int N;
	fin >> N;
	Basic.assign(100, 0);
	Numbers();
	fout << dress(N - 1);
	fout.close();
}