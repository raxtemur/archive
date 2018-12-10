#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vecSumm;

int main()
{
	int n, a, 
		index_left = 0,
		summ = 0;
	fin >> n;
	for (int i = 0; i < n; i++)
	{
		fin >> a;
		if (summ + a > 0) 
		{
			summ = summ + a;
			vecSumm.push_back(summ);
		}
		else	summ = 0;
	}
	fout << *max_element(vecSumm.begin(), vecSumm.end());
}