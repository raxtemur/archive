#include <fstream>
#include <map>
#include <iterator>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <string, string> Synonim;

int main()
{
	int N;
	string Key, Value;
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> Key >> Value;
		Synonim.insert(pair<string, string>(Key, Value));
		Synonim.insert(pair<string, string>(Value, Key));
	}
	fin >> Key;
	fout << Synonim.at(Key);
}