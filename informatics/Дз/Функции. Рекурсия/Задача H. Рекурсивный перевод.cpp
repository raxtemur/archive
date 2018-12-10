#pragma comment(linker, "/STACK:100000000")
#include<iostream>
using namespace std;

void Transl(int sys, unsigned long long int var)
{
	if (var >= sys) Transl(sys, (var/sys));
	cout << (var%sys);
}

int main()
{
	unsigned long long int  var;
	int sys;
	cin >> sys >> var;
	cout << var << "(10)=";
	Transl(sys, var);
	cout << "(" << sys << ")";
	return(0);
}