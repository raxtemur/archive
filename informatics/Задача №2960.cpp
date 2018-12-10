#include <iostream>
 using namespace std;

	int main()
{
	int sch, sys;
	cin>>sys>>sch;
	if ((sys==sch) || ((sys!=1)&&(sch!=1))) { cout<<"YES"; }
	else { cout<<"NO"; }
	return 0;
}
