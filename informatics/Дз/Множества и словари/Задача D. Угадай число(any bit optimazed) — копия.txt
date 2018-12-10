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
set<int> ThisQuesion, *YES, *NO;

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
	YES = new set<int>[2];
	NO = new set<int>[2];
	int numYES = 0,
		numNO = 0,
		magic = 1; //to be faster
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
		if (Answer == "YES")
		{
			if (YES[numYES].empty()) YES[abs(numYES - 1)] = ThisQuesion;
			else  set_intersection(YES[numYES].begin(), YES[numYES].end(), ThisQuesion.begin(), ThisQuesion.end(), inserter(YES[abs(numYES - 1)], YES[abs(numYES - 1)].end()));
			YES[numYES].clear(); numYES = abs(numYES - 1);
		}
		else
		{
			set_union(NO[numNO].begin(), NO[numNO].end(), ThisQuesion.begin(), ThisQuesion.end(), inserter(NO[abs(numNO - 1)], NO[abs(numNO - 1)].end()));
			NO[numNO].clear();	numNO = abs(numNO - 1);
		}
		ThisQuesion.clear();
		getline(fin, Question);
	}
	set_difference(YES[numYES].begin(), YES[numYES].end(), NO[numNO].begin(), NO[numNO].end(), ostream_iterator<int>(fout, " "));
}