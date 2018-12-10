#include <fstream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <string, string> Lat_Eng;

int main()
{
	int N;
	fin >> N;
	bool AnyMeen; 
	string EngWord, LatWord;
	for (int i = 0; i < N; i++)
	{
		fin >> EngWord;
		for (int i = 0; i < 3; i++) fin.get();
		AnyMeen = true;
		while ( AnyMeen )
		{
			AnyMeen = 0;
			fin >> LatWord;
			if (LatWord[LatWord.size() - 1] == *",") { LatWord.erase(LatWord.end() - 1); AnyMeen = 1; }
			if ((Lat_Eng[LatWord].size()) > 0)  Lat_Eng[LatWord] = Lat_Eng[LatWord] + ", " + EngWord;
			else Lat_Eng[LatWord] = EngWord;
			//if (Lat_Eng.find(LatWord) == Lat_Eng.end()) Lat_Eng.insert(pair<string, string>(LatWord, EngWord));
			//else Lat_Eng.at(LatWord) = Lat_Eng.at(LatWord) + ", " + EngWord;
		}
	}
	fout << Lat_Eng.size() << endl;
	for (auto it = Lat_Eng.begin(); it != Lat_Eng.end(); it++)	fout << it->first << " - " << it->second << endl;
}