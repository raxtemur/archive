#include <iostream>
#include <cmath>
using namespace std;
	 int main()
	{
	int a1, a2, a3;
	div_t n;
	cin>>a1;

	n=div(a1, 100);
	a1=n.quot;
	a2=n.rem;
	n=div(a2, 10);
	a2=n.quot;
	a3=n.rem;
	cout<<a1+a2+a3;
	return 0;
	}

