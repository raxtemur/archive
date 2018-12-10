#pragma comment(linker, "/STACK:100000000")
#include<iostream>
using namespace std;

void Sec()
{
	int a;
	cin >> a;
	if (a) Sec();
	cout << a << endl;
}

int main()
{
	Sec();
}