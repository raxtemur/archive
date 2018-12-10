#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	string str;
	int j = 0;
	while (getline(fin, str))
	{
		j++;
		for (int i = 0; i < str.size(); i++)
		{
			if ((str[i] - 'a' < 27) && (str[i] - 'a' > 0)) str[i] = (str[i] - 'a' - 1 + j) % 27 + 'a' + 1;
			if ((str[i] - 'A' < 27) && (str[i] - 'A' > 0)) str[i] = (str[i] - 'A' - 1 + j) % 27 + 'A' + 1;
		}
		fout << str << endl;
	}
}