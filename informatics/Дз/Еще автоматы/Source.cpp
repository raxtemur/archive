#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

bool ultra_lower_bound(unsigned long long _Left, unsigned long long _Right, unsigned long long _Width, unsigned long long _Height, unsigned long long _Num)
{
	if ((((_Right + _Left) / 2) / _Width) * (((_Right + _Left) / 2) / _Height) < _Num) return true;
	else return false;
}

int main()
{
	unsigned long long Left = 0,
		Right = 18446744073709551615;
	int w, h, n;
	fin >> w >> h >> n;

	while (Right != Left)
	{
		if (ultra_lower_bound(Left, Right, w, h, n))
			Left = ((Right - Left) / 2) + Left + 1;
		else Right = ((Right - Left) / 2) + Left;
	}
	fout << Left;
}