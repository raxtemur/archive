#include <iostream>
using namespace std;

	int main()
	{
		int n;
		cin>>n;
		cout<<  10*(n/1000)+((n%1000)/100)-((n%100)/10)-(10*(n%10))+1;
		return 0;
	}
