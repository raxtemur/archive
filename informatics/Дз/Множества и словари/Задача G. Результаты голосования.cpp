#include <fstream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <string, int> Parties;
multimap <int, string> PartiesSortedByKeys;
int main()
{
	int N; 
	string NameOfPart;
	fin >> N;
	getline(fin, NameOfPart);
	for (int i = 0; i < N; i++)
	{
		getline(fin, NameOfPart);
		if (Parties.find(NameOfPart) == Parties.end())	Parties.insert(pair<string, int>(NameOfPart, 1));
		else Parties.at(NameOfPart)++;
	}
	for (auto it = --Parties.end(); it != --Parties.begin(); it--)	PartiesSortedByKeys.insert(pair<int, string>(it ->second, it->first));
	for (auto it = --PartiesSortedByKeys.end(); it != --PartiesSortedByKeys.begin(); it--)
	{
		fout << it->second << endl ;
	}
}