#include <vector>
#include <fstream>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

set <string>  AllLangs;
vector<string> ThisManKnowladge, KnownByAll, Buffer;

int main()
{
	int N, M;
	string Lang;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> M;
		for (int j = 0; j < M; j++)
		{
			fin >> Lang;
			ThisManKnowladge.insert(ThisManKnowladge.end(), Lang);
			AllLangs.insert(Lang);
		}
		sort(ThisManKnowladge.begin(), ThisManKnowladge.end());
		if (i > 0)
		{
			set_intersection(ThisManKnowladge.begin(), ThisManKnowladge.end(),
				KnownByAll.begin(), KnownByAll.end(), back_inserter(Buffer));
			sort(Buffer.begin(), Buffer.end());
			KnownByAll = Buffer;
		}
		else KnownByAll = ThisManKnowladge;
		ThisManKnowladge.clear();
		Buffer.clear();
	}
	fout << KnownByAll.size() << endl;
	for (auto it = KnownByAll.begin(); it != KnownByAll.end(); it++) fout << *it << endl;
	fout << AllLangs.size() << endl;
	for (auto it = AllLangs.begin(); it != AllLangs.end(); it++) fout << *it << endl;
}