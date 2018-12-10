#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int i = 0,
		Lines = 0,
		Words = 0,
		Letters = 0,
		LastSymb = -1; // 0 - letter, 1 - ' ' or '\n', 2 - anothersymbol
	char a;
	while (fin.get(a))
	{
		i++;
		if ((((a - 'a') > -1) && ((a - 'a') < 27)) || ((a - 'A' > -1) && (a - 'A' < 27))) { Letters++; LastSymb = 0; }
		else
		{
			if (LastSymb == 0) Words++;
			if (a == ' ' || a == '\n') LastSymb = 1;
			else LastSymb = 2;

			if (a == '\n' || a == EOF)
				Lines++;
		}
	}
	Lines++;
	if (LastSymb == 0) Words++;
	fout << "Input file contains:\n" << Letters << " letters\n" << Words << " words\n" << Lines << " lines";
}