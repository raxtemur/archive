#include <fstream>
#include <sstream>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int a = 0, sum = 0;
	string str;
	stringstream lin;
	while (getline(fin, str))
	{
		lin << str;
		while (lin >> a) sum = sum + a;
		fout << sum << endl;
		sum = 0;
		lin.clear();
	}
}