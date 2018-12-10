
#include <iostream>
#include <string>
using namespace std;

int main()
{	
	string W1, W2, W3;
	cin >> W1 >> W2;
	W3 = W2;
	W2 = W1;
	W1 = W3;
	cout << W1 + " " + W2;
}

