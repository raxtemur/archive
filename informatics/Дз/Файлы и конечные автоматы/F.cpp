#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
map<string, int> Parties;
vector<string> ListOfNames;


int main()
{
	float SummVoces = 0;
	string NameOfParty, str, Position;
	getline(fin, str);
	getline(fin, str);
	while (str != "VOTES:")
	{
		ListOfNames.push_back(str);
		Parties.insert(pair<string, int>(str, 0));
		getline(fin, str);
	}

	while (getline(fin, str)) {	Parties.at(str)++; SummVoces++; }

	for (int i = 0; i < ListOfNames.size(); i++)
	{
		auto it = Parties.find(ListOfNames[i]);
		if (((it->second) / SummVoces) > 0.07)  
			fout << it->first << endl; 
	}
	//for (auto it = Parties.begin(); it != Parties.end(); it++)	if ((it->second) / SummVoces > 0.07) { fout << it->first; }
}