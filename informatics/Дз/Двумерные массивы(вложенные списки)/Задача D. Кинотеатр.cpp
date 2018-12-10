#include<iostream>
using namespace std;


void Draw(int **Array, int Height, int Width)
{
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			cout << Array[i][j] << " ";
		}
		cout << endl;
	}
}

int **Read( int Height, int Width)
{
	int **Array = new int *[Height];
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		Array[i] = new int[Width];
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			cin>>Array[i][j];
		}
	}
	return(Array);
}

int FindLine(int **Array, int Height, int Width, int Places)
{
	int FreePlaces = 0, MaxLine = -1;
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			if (Array[i][j] == 0)	
			{
				FreePlaces++;
				if (FreePlaces == Places)
				{
					Height = i;
					MaxLine = i;
					break;
				}
			}
			else
			{
				FreePlaces = 0;
			}
		}
		FreePlaces = 0;
	}
	return(MaxLine+1);
}

int main()
{
	int n = 1, m = 1, k;
	cin >> n >> m;
	int **Theater;
	Theater = Read(n, m);
	cin >> k;
	cout<<FindLine(Theater, n, m, k);
	
}