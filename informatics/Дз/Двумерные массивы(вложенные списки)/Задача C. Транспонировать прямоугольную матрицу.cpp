#include<iostream>
using namespace std;

	
void Draw(int **Array, int Height, int Width)
{
	for (int i = 0; i < Height; i++)
	{
		for (int k = 0; k < Width; k++)
		{
			cout << Array[i][k]<<" ";
		}
		cout << endl;
	}
}

int **Transpose(int **ArToTr, int Height, int Width)
{

	int **ArAfterTr = new int*[Width]; //Height of ArArftreTr = Wighth of ArToTr 
	for (int i = 0; i < Width; i++)
	{
		ArAfterTr[i] = new int[Height]; //Width of ArArftreTr = Height of ArToTr
		for (int k = 0; k < Height; k++)
		{
			ArAfterTr[i][k] = ArToTr[k][i];
		}
	}
	return(ArAfterTr);
}

int main()
{
	int Nk=1, Ni=1;
	cin >> Ni >> Nk;
	int **Ar = new int*[Ni];
	for (int i = 0; i < Ni; i++) //Изменение горизонтали(Oi)
	{
		Ar[i] = new int[Nk];
		for (int k = 0; k < Nk; k++)	//Каждая точка по вертикали(Ok)
		{
			cin >> Ar[i][k];
		}		
	}
	int **TrAr = Transpose(Ar, Ni, Nk);
	Draw(TrAr, Nk, Ni);
}