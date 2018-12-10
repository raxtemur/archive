#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> maxin(3);

int main()
{
	string FIO;
	int klass, ball;
	while (fin >> FIO) 
	{ 
		fin >> FIO;
		fin >> klass;
		fin >> ball;
		if (maxin[klass - 9] < ball)  maxin[klass - 9] = ball; 
	}
	fout << maxin[0] << " " << maxin[1] << " " << maxin[2];
}