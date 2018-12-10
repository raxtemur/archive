#include <iostream>
	 using namespace std;
	 int main()
	 {
		int a,b,c;
		div_t z;

		cin>>a>>b;

		z=div(b, a);
		c=z.quot;
		cout<<c<<endl;
		return 0;
	 }


