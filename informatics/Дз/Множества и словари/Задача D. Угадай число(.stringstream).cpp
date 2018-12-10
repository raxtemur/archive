#include <vector>
#include <fstream>
#include <sstream>
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
}*/

int main()
{
	ios::sync_with_stdio(false);
	int N, Var;
	string Question, Answer;
	stringstream VarStream;
	fin >> N;
	CouldBe = new set<int>[2];
	for (int i = 0; i < N; i++) CouldBe[0].insert(i + 1);
	int num = 0;
	getline(fin, Question);
	getline(fin, Question);
	while (Question != "HELP")
	{
		getline(fin, Answer);
		VarStream << Question;
		while (VarStream >> Var) ThisQuesion.insert(Var);

		if (Answer == "YES") set_intersection(CouldBe[num].begin(), CouldBe[num].end(), ThisQuesion.begin(), ThisQuesion.end(), inserter(CouldBe[abs(num - 1)], CouldBe[abs(num - 1)].end()));
		else set_difference(CouldBe[num].begin(), CouldBe[num].end(), ThisQuesion.begin(), ThisQuesion.end(), inserter(CouldBe[abs(num - 1)], CouldBe[abs(num - 1)].end()));
		CouldBe[num].clear();
		num = abs(num - 1);
		
		VarStream.clear();
		ThisQuesion.clear();

		getline(fin, Question);
	}
	copy(CouldBe[num].begin(), CouldBe[num].end(), ostream_iterator<int>(fout, " "));
}