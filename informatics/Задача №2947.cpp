#include <iostream>
#include <cmath>
using namespace std;
	 int main()
	{
	int m,h,n;
	div_t k;
	cin>>n;
	k=div(n, 60);
	h=k.quot;
	m=k.rem;
	k=div(h, 24);
	h=k.rem;
	cout<<h<<endl<<m;
	cin>>n;
	return 0;
	}

