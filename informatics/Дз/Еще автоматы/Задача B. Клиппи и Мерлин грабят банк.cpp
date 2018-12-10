#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vec;

int main()
{
	int n, k;
	int a;
	int i, j, i_Max, j_Max, max_i;

	fin >> n >> k;
	i = 0; j = k + 1;
	max_i = 0;
	i_Max = i; j_Max = j;

	for (int p = 0; p < n; p++)
	{
		fin >> a;

		if (p < k + 2) vec.push_back(a);
		else
		{
			vec.push_back(a);
			if (vec[max_i] < vec[p - k - 1]) max_i = p - k - 1;
			if ((vec[i_Max] + vec[j_Max]) < (vec[max_i] + vec[p])) { i_Max = max_i; j_Max = p;}
		}
	}
	fout << i_Max + 1 << " " << j_Max + 1;
}