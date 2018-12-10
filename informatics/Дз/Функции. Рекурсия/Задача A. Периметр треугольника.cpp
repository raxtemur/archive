#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;



double length(double x1, double y1, double x2, double y2)
{
	double length = sqrt(((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
	return (length);

}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double a, b, c, P;
	a = length(x1, y1, x2, y2);
	b = length(x2, y2, x3, y3);
	c = length(x1, y1, x3, y3);
	P = a + b + c;
	cout << fixed << setprecision(7) << P;
}