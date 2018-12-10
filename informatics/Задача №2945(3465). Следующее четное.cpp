#include <iostream>
#include <cmath>
using namespace std;
	 int main()
	{
	int a;
	div_t n;
	cin>>a;

	n=div(a, 2);
	a=n.quot*2+2;
	cout<<a;
	return 0;
	}
