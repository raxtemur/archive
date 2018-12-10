#include <iostream>
using namespace std;

int main()
{
int h, a, b, d;
cin>>h>>a>>b;
h=h-a;
d=(h+(a-b-1))/(a-b)+1;
cout<<d;
return 0;
}
