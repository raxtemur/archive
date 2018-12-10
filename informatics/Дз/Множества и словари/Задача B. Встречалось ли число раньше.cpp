#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
set<int> setCh;
pair<set<int>::iterator, bool> in;

int main()
{
	int a;
	while (fin >> a)
	{
		in = setCh.insert(a);
		if (in.second) fout << "NO\n";
		else fout << "YES\n";
	}
	fin.close();
	fout.close();
}