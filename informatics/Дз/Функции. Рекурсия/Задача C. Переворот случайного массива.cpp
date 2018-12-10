#pragma comment(linker, "/STACK:100000000")

#include<iostream>
#include<iomanip>
using namespace std;

int **A;
int N, M;
int calc;

void Create()
{
	A = new int *[N];
	for (int k = 0; k < N; k++)
	{
		A[k] = new int[M];
	}

}

void PrintViaReprint()
{
	calc++;
	int j = calc / N;
	int	i = calc % N;
	A[i][j] = rand() % 10;	cout << A[i][j] << " ";
	if (i == (N - 1)) { cout << endl; }
	if (calc < N*M - 1){ PrintViaReprint();}
	cout << A[i][j] << " ";
	if (i == 0) { cout << endl; }
}

int main()
{
	
	cin >> N >> M;
	Create();
	calc = -1;
	PrintViaReprint();

}