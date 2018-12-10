// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//


#include <iostream>
using namespace std;

int main()
{	
	int i, n, x, x_max, x_min, sum;
	double value;
	cin >> n;
	i = 0;
	x_max = 0; x_min = 100; sum = 0;
	while (i < n)
	{
		i++;
		cin >> x;
		if (x_max < x) { x_max = x; }
		if (x_min > x) { x_min = x; }
		sum += x;
	}
	value = double(sum - x_min - x_max) / (n - 2);
	cout << value;
    return 0;
}

