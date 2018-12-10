#include<iostream>
using namespace std;

int Height;
int Width;
int **Star;


void Draw()
{
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			 cout << char(Star[i][j]) << " "; 
		}
		cout << endl;
	}
}

void Create()
{
	Star = new int *[Height];
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		Star[i] = new int[Width];
		for (int j = 0; j < Width; j++)
		{
			Star[i][j] = '.';
		}
	}
}

void Read()
{
	for (int i = 0; i < Height; i++)	//Изменение горизонтали(Oi)
	{
		for (int j = 0; j < Width; j++)		//Изменение вертикали(Oj)
		{
			cin >> Star[i][j];
		}
	}
}



void StarIt()
{
	for (int i = 0; i < Height; i++) //Изменение горизонтали(Oi)
	{
		Star[i][i] = '*';
		Star[i][Width - 1 - i] = '*';
		Star[i][Width / 2] = '*';
		Star[Height / 2][i] = '*';
	}

}

int main()
{
	cin >> Height;
	Width = Height;
	Create();
	StarIt();
	Draw();
}