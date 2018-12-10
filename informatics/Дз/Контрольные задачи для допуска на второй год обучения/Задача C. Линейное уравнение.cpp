// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//


#include <iostream>
using namespace std;

int main()
{	
	long long a, b, x;
	cin >> a >> b;
	if ((a == 0) & (b == 0)) { cout << "INF"; }
	else
	{
		if (a == 0) { cout << "NO"; }
		else
		{
			if (b%a != 0) { cout << "NO"; }
			else { cout << -b / a; }
		}
	}
    return 0;
}

