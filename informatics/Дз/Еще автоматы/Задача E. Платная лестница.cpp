#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vecL(2), vecS(2);


int main()
{
	int n, a;
	fin >> n;
	
	for (int i = 2; i < n + 2; i++)
	{
		fin >> a;
		vecL.push_back(a);
		vecS.push_back(min(vecS[i - 2], vecS[i - 1]) + vecL[i]);
	}
	if (vecS == vecS) 1 - 1;
	auto it = vecS.end() - 1;
	fout << *it;
}