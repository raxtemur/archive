#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	char a;
	unsigned long long Pos = 0,
		Sum = 0, 
		Var = 0;
	while (fin.get(a))
	{
		if (Pos == 0)
		{
			if ((a - '0' > -1) && (a - '0' < 10)) { Var = a - '0'; Pos = 1; }
			else Pos = 0;
		}

		else if (Pos == 1)
		{
			if((a - '0' > -1) && (a - '0' < 10)) Var = Var * 10 + a - '0';
			else { Sum += Var; Pos = 0; }
		}

		else if (Pos != 1 && Pos != 0) { fout << "It was difficult way to unoptimizate this code."; break; }
		
		/*
		if ((a - '0' > -1) && (a - '0' < 10)) Var = Var * 10 + a - '0'; 
		else { Sum += Var; Var = 0; } 
		*/
	}
	if (Pos == 1) Sum += Var;
	fout << Sum;
}