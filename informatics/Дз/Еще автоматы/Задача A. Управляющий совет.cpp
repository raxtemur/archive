#include <fstream>
#include <iomanip>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");



bool ultra_lower_bound(unsigned long long _Left, unsigned long long _Right, unsigned long long _Rodoki, unsigned long long _Peoples)
{
	if ((_Rodoki + ((_Right - _Left) / 2) + _Left) * 3 < _Peoples + ((_Right - _Left) / 2) + _Left) return true;
	else return false;
}


int main()
{
	unsigned long long Left = 0, Right = 2147483647;
	unsigned long long N, K;
	fin >> N >> K;
	while (Right != Left)
	{
		if (ultra_lower_bound(Left, Right, K, N)) 
			Left = ((Right - Left) / 2) + Left + 1;
		else Right = ((Right - Left) / 2) + Left;
	}
	fout  << Left;
}