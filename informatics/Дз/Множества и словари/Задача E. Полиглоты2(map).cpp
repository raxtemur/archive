#include <fstream>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <string, int> Lang;

int main()
{
	int N, M,
		Count_KnownByAll = 0;
	stringstream AllLangs, KnownByAll;
	string A,
		Str_KnownByAll = "",
		Str_AllLangs = "";
	fin >> N;

	for (int i = 0; i < N; i++)
	{
		fin >> M;
		for (int j = 0; j < M; j++)
		{
			fin >> A;
			if (Lang.find(A) == Lang.end())	Lang.insert(pair<string, int>(A, 1));
			else Lang.at(A) = Lang.at(A)++;
		}
	}

	for (auto it = --Lang.end(); it != --Lang.begin(); it--)
	{
		AllLangs << it->first << " " << endl;
		if (it->second == N)
		{
			Count_KnownByAll++;
			KnownByAll << it->first << " " << endl;
		}
	}
	
	Str_AllLangs = AllLangs.str();
	Str_KnownByAll = KnownByAll.str();

	fout << Count_KnownByAll << endl
		<< Str_KnownByAll
		<< Lang.size() << endl
		<< Str_AllLangs;
}