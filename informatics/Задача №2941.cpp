#include <iostream>

using namespace std;
 int main()
{
	int a;
	div_t n;
	cin>>a;
	n=div(a, 10);
	a=n.rem;
	cout<<a;
	cin>>a;
	return 0;
}
