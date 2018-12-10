#include<iostream>
using namespace std;

int main ()
{
unsigned long long N;
long Del, Num;
Del=2;
Num=0;
cin>>N;
	do
	{
		while (N%Del!=0)
		{
			if (Num>1) {cout<<Del<<"^"<<Num<<"*";}
			if (Num==1) {cout<<Del<<"*";}
			if ((N/Del==2)&&(N%Del==0)) { Del=N-1;}
			Del=Del+1;
			Num=0;
		}
	N=N/Del;
	Num=Num+1;

	}
	while (N!=1);
if (Num>1) {cout<<Del<<"^"<<Num;}
if (Num==1) {cout<<Del;}
}