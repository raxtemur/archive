#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


vector<int> Basic;

void Numbers()
{
	int a;
	while (fin >> a) { if (a <= Basic.size()) { Basic[a - 1]++; } }
}

int main() 
{
	int N;
	fin >> N;
	Basic.assign(N, 0);
	Numbers();
	int max = Basic[0];
	int BasicSize = Basic.size();
	for (int i = 1; i < BasicSize; i++) { if (max < Basic[i]) { max = Basic[i]; } }
	for (int i = 0; i < BasicSize; i++) { if (Basic[i] == max) { fout << (i + 1) << " "; } }
	fout.close();
}