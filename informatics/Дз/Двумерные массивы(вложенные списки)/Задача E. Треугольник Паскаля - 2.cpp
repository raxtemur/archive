#include<iostream>
using namespace std;

void pout(int pasv)
{
	int l = 1, ctrl=pasv;
	for (int i = 0; i < 6; i++)
	{
		if (ctrl=ctrl/10)
		{
			l++;
		}
		else
		{
			for (i = 0; i < 6-l; i++)
			{
				cout << " ";
			}
			cout << pasv;
			break;
		}

	}
}

void Draw(int **Array, int Height)
{
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < i+1; j++)		//Изменение вертикали(Oj)
		{
			pout(Array[i][j]);
		}
		cout << endl;
	}
}


int **Pascaling(int n)
{
	int **Pascal = new int *[n];
	for (int i = 0; i < n; i++)
	{
		Pascal[i] = new int[i + 1];
		for (int k = 0; k < i + 1; k++)
		{
			if ((k != 0) && (k != i))
			{
				Pascal[i][k] = Pascal[i - 1][k] + Pascal[i - 1][k - 1];
			}
			else
			{
				Pascal[i][k] = 1;
			}
		}


	}

	return(Pascal);
}



int main()
{
	int n = 1, m = 1, k;
	cin >> n;
	int **Pascal=Pascaling(n);
	Draw(Pascal, n);
	
}