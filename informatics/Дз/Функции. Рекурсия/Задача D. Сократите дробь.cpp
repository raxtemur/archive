#include<iostream>
#include<iomanip>
using namespace std;

struct Fraction
{
	int Denominator; // знаменатель
	int Numerator; // числитель
};

int GCD(int n, int m)
{
	if (m == 0) { return n; }
	else { return GCD(m, (n % m)); }
}

Fraction ReduseFraction(Fraction Fr)
{
	int gcd;
	gcd = GCD(Fr.Numerator, Fr.Denominator);
	Fr.Numerator = Fr.Numerator / gcd;
	Fr.Denominator = Fr.Denominator / gcd;
	return (Fr);
}

int main()
{
	Fraction First;
	Fraction Getted;
	cin >> First.Numerator >> First.Denominator;
	Getted = ReduseFraction(First);
	cout << Getted.Numerator << " " << Getted.Denominator;
}