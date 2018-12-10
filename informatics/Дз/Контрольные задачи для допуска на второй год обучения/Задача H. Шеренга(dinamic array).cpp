#include <iostream>
using namespace std;

int main()
{
	int N, HPetr;
	cin >> N;
	int *H =  new int[N+1];
	int i=0;
	while (i<=N-1)
	{
		cin >> H[i];
		++i;
	}
	H[i] = 0;
	cin >> HPetr;
	i = 0;
	while (i<=N)
	{
		if (HPetr > H[i]) { cout << i+1; break; }
		++i;
	}
}