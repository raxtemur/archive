#include <fstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	unsigned long long N, buf,
		t = 1,
		j = 0;
	fin >> N;
	for (int i = 1; i < N; i++)
	{
		buf = t;
		t = t + j;
		j = buf;
	}
	fout << t * 2 + j;
}