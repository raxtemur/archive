#pragma comment(linker, "/STACK:100000000")
#include<iostream>
using namespace std;

int N;
int PQ;

void MoveLog(int n, int x, int y)
{
	int NextPos = (x % 3) + 1;
	int PrevPos = ((x + 1) % 3) + 1;
	if (n == 1)
	{
		cout << n << " " << x << " " << NextPos << endl; PQ++;
		if (y != NextPos)  {cout << n << " " << NextPos << " " << y << endl; PQ++;}
	}

	else
	{
		MoveLog(n - 1, x, PrevPos);
		cout << n << " " << x << " " << NextPos << endl; PQ++;
		if (NextPos == y) { MoveLog(n - 1, PrevPos, y); }
		else 
		{ 
			MoveLog(n - 1, PrevPos, x);
			cout << n << " " << NextPos << " " << y << endl; PQ++;
			MoveLog(n - 1, x, y);
		}
	}
}



int main()
{
	cin >> N;
	MoveLog(N, 1, 3);
	//cout << PQ;
}