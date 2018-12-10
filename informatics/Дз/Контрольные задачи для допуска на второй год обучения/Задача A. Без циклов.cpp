#include<iostream>
using namespace std;

int main()
{
int k, n;
bool pageup;
cin>>k>>n;
pageup=(n%k!=0);
cout<<((n-1)/k)+1<<' '<<(n-1)%k+1;
}
