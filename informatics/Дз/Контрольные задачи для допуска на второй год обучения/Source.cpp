#include <iostream>
using namespace std;

int main()
{
	int N, Ctrl;
	cin >> N;
	N = N-1;
	int *H = new int[N];
	int i=0, w;
	
	//������ �������
	while (i<=N)
	{
		cin >> H[i];
		++i;
	}

	i = 0; w = 0;
	//�������� ������������� ���������
	while (i <= N)
	{
		Ctrl = H[i];
		if (H[i] != 0)
		{
			while (w <= N)
			{
				if ((i != w) & (H[w] == Ctrl)) { H[w] = 0; H[i] = 0; }
				++w;
			}
		}
		++i;
		w = 0;
	}
	
	i = 0;
	//������ �������� �������
	while (i <= N)
	{
		if (H[i]) { cout << H[i]<<" "; }
		++i;
	}

}