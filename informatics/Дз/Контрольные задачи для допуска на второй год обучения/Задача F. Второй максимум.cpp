
#include <iostream>
using namespace std;

int main()
{
	int Ch;
	unsigned long long CG1=0, CG2=0;
	while (true)
	{
		cin >> Ch;
		if (Ch == 0) { break; }
		if (Ch > CG2)
		{
			CG2 = Ch;
		}
		if (Ch > CG1)
		{
			CG2 = CG1;
			CG1 = Ch;
		}

	}
	cout << CG2;
}

