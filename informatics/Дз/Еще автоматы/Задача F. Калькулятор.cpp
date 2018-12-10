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
	int X, n, on3, on2, in1;
	fin >> X;
	vec.push_back(0);
	vec.push_back(0);
	for (int i = 2; i < X + 1; i++)
	{
		on3 = 1000000;
		on2 = 1000000;
		if (!(i % 3)) on3 = vec[i / 3];
		if (!(i % 2)) on2 = vec[i / 2];
		in1 = vec[i - 1];
		vec.push_back(min(min(on3, in1), on2) + 1);
	}
	fout << vec[X];
}