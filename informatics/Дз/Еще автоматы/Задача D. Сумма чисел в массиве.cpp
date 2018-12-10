#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vecSumm, vecleftIndex;

int main()
{
	int n, a, i,
		leftIndex = 0,
		summ = 0;
	fin >> n;
	for (i = 0; i < n; i++)
	{
		fin >> a;
		if (summ + a > 0)
		{
			summ = summ + a;
			vecSumm.push_back(summ);
			vecleftIndex.push_back(leftIndex);
		}
		else
		{
			summ = 0;
			vecSumm.push_back(0);
			vecleftIndex.push_back(leftIndex);
			leftIndex = i + 1;
		}
	}
	i = max_element(vecSumm.begin(), vecSumm.end()) - vecSumm.begin();
	fout << vecleftIndex[i] + 1 << " " << i + 1;
}