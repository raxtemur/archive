#include <vector>
#include <fstream>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;


ifstream fin("input.txt");
ofstream fout("output.txt");

/*set <string>  AllLangs;
vector<string> ThisManKnowladge, KnownByAll, Buffer;*/
set<int> ThisQuesion, *CouldBe;
vector<int> Buffer;

/*set<int> VecToSet(vector<int> From)
{
	set<int> To;
	for (auto it = From.begin(); it != From.end(); it++) To.insert(*it);
	//for each (int Var in From) To.insert(Var);
	return(To);
}

void STurn(string &str)
{
	string _str;
	while (str[0] > 0)
	{
		_str.push_back(str.back());
		str.pop_back();
	}
	str = _str;
}


string stos(string &line)
{
	string word;
	if (line.length() > 0)
	{
		for (word = line.back(); (line.length() != 0) && (line.back() != ' '); word += line.back())
			line.pop_back();
		if (line.length() != 0) line.pop_back();
		word.pop_back();
	}
	else word = "";
	return word;
}*/

int main()
{
	ios::sync_with_stdio(false);
	int N, Var = 0;
	string Question, Answer;
	fin >> N;
	CouldBe = new set<int>[2];
	for (int i = 0; i < N; i++) CouldBe[0].insert(i + 1);
	int num = 0;
	getline(fin, Question);
	getline(fin, Question);
	while (Question != "HELP")
	{
		getline(fin, Answer);
		for (auto it = Question.begin(); it != Question.end(); it++)
		{
			if (*it != ' ') Var = Var * 10 + *it - '0'; 
			else {	ThisQuesion.insert(Var); Var = 0;  }
		}
		ThisQuesion.insert(Var); Var = 0;
		if (Answer == "YES") set_intersection(CouldBe[num].begin(), CouldBe[num].end(), ThisQuesion.begin(), ThisQuesion.end(), inserter(CouldBe[abs(num - 1)], CouldBe[abs(num - 1)].end()));
		else set_difference(CouldBe[num].begin(), CouldBe[num].end(), ThisQuesion.begin(), ThisQuesion.end(), inserter(CouldBe[abs(num - 1)], CouldBe[abs(num - 1)].end()));
		CouldBe[num].clear();	num = abs(num - 1);
		ThisQuesion.clear();

		getline(fin, Question);
	}
	copy(CouldBe[num].begin(), CouldBe[num].end(), ostream_iterator<int>(fout, " "));
}