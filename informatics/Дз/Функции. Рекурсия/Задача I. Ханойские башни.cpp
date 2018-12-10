#pragma comment(linker, "/STACK:100000000")
#include<iostream>
using namespace std;

int N;
/*
int *First = new int[N+1];
int *Second = new int[N+1];
int *Third = new int[N+1];
long int PQ = 0;

int Take(int *TakeFrom)
{
	if (TakeFrom == NULL) { cout << "Error: taking from NULL"; system("pause"); }
	int last = TakeFrom[0];
	int took = TakeFrom[last];
	TakeFrom[0] -= 1;
	TakeFrom[last] = 0;
	TakeFrom = NULL;
	return (took);
}

void Put(int *PastTo, int number)
{
	if (PastTo == NULL) { cout << "Error: puting in NULL"; system("pause"); }
	PastTo[0] += 1;
	int put = PastTo[0];
	if (((put - 1) != 0)&& (PastTo[put - 1] < number) && (PastTo[put - 1] > 0)) { cout << "Error: trying to put on littler disk"; system("pause"); }
	PastTo[put] = number;
	PastTo = NULL;
}

void MoveAr(int n, int x, int y)
{
	int *X = NULL, *Y = NULL;
	switch (x)
	{
	case 1: X = First; break;
	case 2: X = Second; break;
	case 3: X = Third;break;
	default: {cout << "Error 404x"; system("pause"); break; }
	}
	switch (y)
	{
	case 1: Y = First; break;
	case 2: Y = Second; break;
	case 3: Y = Third; break;
	default: {cout << "Îøèáêà 404y"; system("pause"); break; }
	}

	int took;
	took = Take(X);
	Put(Y, took);
	//cout << took << " " << x << " " << y << endl;
	PQ++;
	X = NULL;
	Y = NULL;
	//debug
	//cout << x << " " << X[0] << " elements" << endl;
	//cout << y << " " << Y[0] << " elements" << endl;
}
*/

void MoveLog(int n, int x, int y)
{
	if (n == 1) { cout << 1 << " " << x << " " << y << endl; }
	else
	{
		MoveLog(n - 1, x, 6 - (x + y));
		cout << n << " " << x << " " << y << endl;
		MoveLog(n - 1, 6 - (x + y), y);
	}
}



int main()
{
	cin >> N;
	/*for (int i = 1; i < N+1; i++) First[i] = N + 1 - i;
	First[0] = N;
	Second[0] = 0;
	Third[0] = 0;*/
	MoveLog(N, 1, 3);
	//cout << PQ;
}