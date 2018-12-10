#include <iostream>
#include <stdio.h>


using namespace std;

	 int main()
	{
		int N, m, h;
		cin>>N;
		m=N*45+(N/2)*5+((N-1)/2)*15;
		h=m/60;
		m=m%60;
		h=h+9;
		cout<<h<<" "<<m;
		return 0;
	}
