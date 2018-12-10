#include <fstream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
set<int> setAnn, setBorya;
vector<int> vecBuffer;
set<int>::iterator it;
pair<set<int>::iterator, bool> in;

int main()
{
	int Ann, Borya, a;
	fin >> Ann >> Borya;
	fin >> a;
	for (size_t i = 0; i < Ann; fin >> a, i++)	setAnn.insert(a);
	for (size_t i = 0; i < Borya; fin >> a, i++)  setBorya.insert(a);
	
	set_intersection(setAnn.begin(), setAnn.end(), setBorya.begin(), setBorya.end(), back_inserter(vecBuffer));
	fout << vecBuffer.size() << endl;
	copy(vecBuffer.begin(), vecBuffer.end(), ostream_iterator<int>(fout, " "));
	vecBuffer.clear();
	fout << endl;

	set_difference(setAnn.begin(), setAnn.end(), setBorya.begin(), setBorya.end(), back_inserter(vecBuffer));
	fout << vecBuffer.size() << endl;
	copy(vecBuffer.begin(), vecBuffer.end(), ostream_iterator<int>(fout, " "));
	vecBuffer.clear();
	fout << endl;

	set_difference(setBorya.begin(), setBorya.end(), setAnn.begin(), setAnn.end(), back_inserter(vecBuffer));
	fout << vecBuffer.size() << endl;
	copy(vecBuffer.begin(), vecBuffer.end(), ostream_iterator<int>(fout, " "));
	vecBuffer.clear();
	fout << endl;

	fin.close();
	fout.close();
}