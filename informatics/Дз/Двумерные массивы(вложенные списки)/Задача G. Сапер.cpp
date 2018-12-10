#include<iostream>
using namespace std;

int Height;
int Width;
int **Field;


void Draw()
{
	for (int i = 1; i < Height+1; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 1; j < Width+1; j++)		//Изменение вертикали(Oj)
		{
			if (Field[i][j] != -1) { cout << Field[i][j] << " "; }
			else { cout << "* "; }
		}
		cout << endl;
	}
}

void BombUp(int i, int j)
{
	if (Field[i - 1][j - 1] != -1) { Field[i - 1][j - 1] = Field[i - 1][j - 1] + 1; }
	if (Field[i - 1][j]		!= -1) { Field[i - 1][j]	 = Field[i - 1][j]	   + 1; }
	if (Field[i - 1][j + 1] != -1) { Field[i - 1][j + 1] = Field[i - 1][j + 1] + 1; }
	if (Field[i][j - 1]		!= -1) { Field[i][j - 1]	 = Field[i][j - 1]	   + 1; }
	if (Field[i][j + 1]		!= -1) { Field[i][j + 1]	 = Field[i][j + 1]	   + 1; }
	if (Field[i + 1][j - 1] != -1) { Field[i + 1][j - 1] = Field[i + 1][j - 1] + 1; }
	if (Field[i + 1][j + 1] != -1) { Field[i + 1][j + 1] = Field[i + 1][j + 1] + 1; }
	if (Field[i + 1][j]		!= -1) { Field[i + 1][j]	 = Field[i + 1][j]	   + 1; }
}

void Mining()
{
	int Mines = 0, i, j;
	cin >> Mines;
	for (int c = 0; c < Mines; c++)
	{
		cin >> i >> j;
		Field[i][j] = -1;
		BombUp(i, j);
	}

}

int main()
{
	cin >> Height >> Width;
	Field = new int *[Height + 1];
	for (int i = 0; i < Height + 2; i++)
	{
		Field[i] = new int[Width + 1];
		for (int j = 0; j < Width + 2; j++)
		{
			Field[i][j] = 0;
		}
	}
	Mining();
	Draw();
}