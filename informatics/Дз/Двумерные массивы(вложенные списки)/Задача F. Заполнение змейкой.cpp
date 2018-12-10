#include<iostream>
using namespace std;

enum Dir
{
	Left = -1,
	Right = 1
};

void gcout(int var)
{
	const int length = 4;
	int l = 1, ctrl = var;
	for (int i = 0; i < length; i++)
	{
		if (ctrl = ctrl / 10)
		{
			l++;
		}
		else
		{
			for (i = 0; i < length - l; i++)
			{
				cout << " ";
			}
			cout << var;
			break;
		}

	}
}

void Draw(int **Array, int Height, int Width)
{
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			gcout(Array[i][j]);
		}
		cout << endl;
	}
}

int **Zmey(int Height, int Width)
{
	int count = 0;
	Dir Direct = Right;
	int **Zmey = new int *[Height];
	for (int i = 0; i < Height; i++)
	{
		Zmey[i] = new int [Width];
		for (int j = 0; j < Width; j++)
		{
			if (Direct == Right)
			{
				Zmey[i][j] = ++count;
			}
			else
			{
				Zmey[i][Width - j - 1] = ++count;
			}
		}
		Direct = Dir(0 - int(Direct));
	}
	return(Zmey);
}

int main()
{
	int n = 1, m = 1;
	cin >> n >> m;
	int **Z;
	Z = Zmey(n, m);
	Draw(Z, n, m);
	
}