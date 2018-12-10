#include <fstream>
#include <iterator>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	unsigned long long sum = 0, a = 0;
	char it;
	bool Nat = 1;
	string line;
	while (getline(fin, line))
	{
		for (int i = 0; i < line.size(); i++)
		{
			it = line[i];
			if (it != ' ' && it != '-') { a = a * 10 + it - '0'; }
			else
			{
				if (it == '-') Nat = false;
				else
				{
					if (Nat) sum = sum + a;
					else sum = sum - a;
					a = 0;
					Nat = true;
				}
			}
		}
		if (Nat) sum = sum + a;
		else sum = sum - a;
		a = 0;
		Nat = true;
		fout << sum << endl;
		sum = 0;
	}
}
