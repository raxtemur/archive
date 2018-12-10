#include <cmath>
#include <iostream>

using namespace std;
 int main()
{
	int v, t, k;
	const int l=109;
	int x;

	cin>>v>>t;
	k=v*t;
	x=k%l;


	if (x<0) {
	x=x+l;
	}

	cout<<x;
	cin>>t;
	return 0;
}
