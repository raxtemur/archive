#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;
	while (A!=B)
	{
		if (A % 2) 
		{
			A = A - 1;
			cout << "-1" << endl;
		}
		else
		{
			if (A / 2 < B)
			{
				while (A != B)
				{
					A = A - 1;
					cout << "-1" << endl;
				}
			}
			else
			{
				A = A / 2;
				cout << ":2"<< endl;
			}
		}
	}
	cin >> A;
}