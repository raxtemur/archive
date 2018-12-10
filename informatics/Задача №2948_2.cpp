#include <iostream>
#include <conio.h>
using namespace std;


	int main ()
	{
		unsigned int h, m, s;
		cin>>s;

		h=s/3600;
		s=s%3600;

		m=s/60;
		s=s%60;

		h=h%24;
		cout<<h<<":"<<m/10<<m%10<<":"<<s/10<<s%10;
		getch();

	}

