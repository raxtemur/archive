#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
map<string, int> Parties;
vector<string> ListOfNames;
string Sit[2] = {"NO", "YES"};

int main()
{
	int Situation = 1,
		charNum = 0,
		chrs = 0;
	char thisChar;
	while (Situation > 0)
	{
		if (!fin.get(thisChar)) break;
		if ((thisChar - '0' < 10) && (thisChar - '0' > -1))
		{
			charNum = charNum * 10 + thisChar - '0';
			if (charNum > 255) Situation = 0;
		}
		else
		{
			if (thisChar == '.') { charNum = 0; chrs++; if (chrs > 3) Situation = 0; }
			else Situation = 0;
		}
	}
	fout << Sit[Situation];
}