#include<iostream>
#include<iomanip>
using namespace std;


double power(double a1, long int n)
{
	double a = 1;
	if (n < 0)
	{
		n = abs(n);
		a1 = 1 / a1;
	}
	for (long int i = 0; i < n; ++i)
	{
		a = a * a1;
	}
	return (a);
}

int main()
{
	double x, a;
	long int n;
	cin >> a >> n;
	x = power(a, n);
	cout << x;
}