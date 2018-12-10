#include <fstream>
#include <set>
#include <iterator>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
set<int> setChislaaaaaaaa;

int main()
{
	int a;
	while (fin >> a)	setChislaaaaaaaa.insert(a);
	fout << setChislaaaaaaaa.size();
	fin.close();
	fout.close();
}