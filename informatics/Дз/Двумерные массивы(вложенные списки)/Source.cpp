#include<iostream>
using namespace std;

int Height;
int Width;
int **Array;


void Draw()
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

void Create()
{
	Array = new int *[Height];
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		Array[i] = new int[Width];
	}
}

void Read()
{
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			cin >> Array[i][j];
		}
	}
}



void FindSedl()
{
	
	int **IMin  = new int* [Width];
	
	int *JMax = new int[Height];
	for (int i = 0; i < Height; i++)
	{
		JMax[i] = 0;
	}

	for (int i = 0; i < Height; i++)
	{
		IMin[i] = new int[3];
		IMin[i][0] = -1;
		for (int j = 0; j < Width; j++)
		{
			if (j == 0) { IMin[i][0] = Array[i][j]; IMin[i][1] = i; IMin[i][2] = j; }
			if (Array[i][j]>JMax[j]) { JMax[j] = Array[i][j]; }
			if (Array[i][j]<IMin[i][0]) { IMin[i][0] = Array[i][j]; IMin[i][1] = i; IMin[i][2] = j; }
		}
	}

	int x = 0;
	for (int i = 0; i < Height; i++)
	{
		if (IMin[i][0] == JMax[IMin[i][2]])
		{
			++x;
			cout << IMin[i][1] + 1 << " " << IMin[i][2] + 1;
		}
	}
	if (x == 0) { cout << 0; }
}

int main()
{
	cin >> Height >> Width;
	Create();
	Read();
	FindSedl();
}