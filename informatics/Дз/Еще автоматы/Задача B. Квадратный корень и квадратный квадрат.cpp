#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

double Left = 0,
Right = 10000000000,
eps = 0.0000005;

bool ultra_lower_bound(double _Left, double _Right, double _Ans)
{
	if ((pow(((_Right - _Left) / 2) + _Left, 4) + (_Right - _Left) / 2  + _Left) > _Ans) return false;
	else return true;
}


int main()
{
	double a;
	fin >> a;
	while (Right - Left > eps)
	{
		if (ultra_lower_bound(Left, Right, a)) Left = ((Right - Left) / 2) + Left;
		else Right = ((Right - Left) / 2) + Left;
	}
	fout << setprecision(10) << Left*Left;
}