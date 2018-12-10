#include<iostream>
using namespace std;

int sum(int a, int b)
{
	if (b) { a++; b--; sum(a, b); }
	else { return (a); }
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << sum(a, b);
}