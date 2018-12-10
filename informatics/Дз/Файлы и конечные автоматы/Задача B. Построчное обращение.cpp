#include <fstream>
#include <string>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<string> vecOfStrings;
int main()
{
	string strNew, str;
	while (getline(fin, str)) vecOfStrings.push_back(str);
	for (int i = vecOfStrings.size(); i > 0; i--)	
		fout << vecOfStrings[i - 1] << endl;
}