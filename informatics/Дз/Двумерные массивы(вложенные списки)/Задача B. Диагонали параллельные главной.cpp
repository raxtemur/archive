#include<iostream>
using namespace std;

int main()
{
	int n=1;
	cin >> n;
	int **Ar = new int*[n];
	int *z = new int[n];
	for (int i = 0; i < n; i++) //��������� �����������(Oi)
	{
		Ar[i] = new int[n];
		for (int k = 0; k < n; k++)	//������ ����� �� ���������(Ok)
		{
			if (i == 0)	
			{ 
				Ar[0][k] = k; 
				if (k==0)	{ z[k] = 1;  }
				else		{ z[k] = -1; }
				cout << Ar[i][k] << " ";
			}
			else
			{
				if (z[k] == 1) { Ar[i][k] = Ar[i - 1][k] + 1; }
				else		   { Ar[i][k] = Ar[i - 1][k] - 1; }

				if (Ar[i][k] == 0) { z[k] = 0 - z[k]; }
				cout << Ar[i][k] << " ";
			}
		}		
		cout << endl;
	}
}