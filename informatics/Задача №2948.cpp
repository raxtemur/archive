#include <iostream>
using namespace std;


	int main ()
	{
		int h, m, s;
		div_t n, k;
		cin>>s;

		n=div(s, 3600);
		h=n.quot;
		s=n.rem;

		n=div(s, 60);
		m=n.quot;
		s=n.rem;

		h=h%24;

		n=div(m, 10);
		k=div(s, 10);
		cout<<h<<":"<<n.quot<<n.rem<<":"<<k.quot<<k.rem;

	}
