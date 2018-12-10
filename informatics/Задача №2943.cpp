#include <iostream>
#include <cmath>
using namespace std;
	 int main()
	{
	int a;
	div_t n;
	cin>>a;
	n=div(a, 100);
	a=n.rem;
	n=div(a, 10);
	a=n.quot;
	cout<<a;
	return 0;
	}
