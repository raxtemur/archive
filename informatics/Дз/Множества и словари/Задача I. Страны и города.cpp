#include <fstream>
#include <map>
#include <iterator>
#include <string>
#include <sstream>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map <string, string> CityIn;

int main()
{
	int N;
	string Country, City;
	stringstream Cities;
	fin >> N;
	getline(fin, City);
	for (int i = 0; i < N; i++)
	{
		getline(fin, Country);
		Cities << Country;
		Cities >> Country;
		while (Cities >> City)	
			CityIn.insert(pair<string, string>(City, Country));
		Cities.clear();
	}
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		fin >> City;
		fout << CityIn[City] << endl;
	}
}