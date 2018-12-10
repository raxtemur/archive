#include <iostream>
#include <cmath>
using namespace std;

	int main()
	{
		int n, k, kolvo;
		cin >> n >> k;
		kolvo = abs((k % n - n)%n);
		cout << kolvo;
		return 0;
	}
