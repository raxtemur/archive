#include <fstream>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
int magic = 2; //to be any much faster

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	ios::sync_with_stdio(false);
	int N, Var = 0, WasAnsYES = 0;
	string Question, Answer;
	fin >> N;
	int *Massiv = new int[N];
	getline(fin, Question);
	getline(fin, Question);
	while (Question != "HELP")
	{
		getline(fin, Answer);
		for (auto it = Question.begin(); it != Question.end(); it++)
		{
			if (*it != ' ') Var = Var * 10 + *it - '0'; 
			else
			{
				if ((Answer == "YES") && (Massiv[Var] != 0)) { Massiv[Var] = 1; WasAnsYES = 1; }
				if (Answer == "NO") Massiv[Var] = 0;
				Var = 0;
			}
		}
		if (Answer == "YES") {	Massiv[Var] = 1; Var = 0; }
		else { Massiv[Var] = 0;  Var = 0; }
		getline(fin, Question);
	}
	if (WasAnsYES)	{ for (int i = 0; i < N; i++){	if (Massiv[i] == 1)	fout << i << " ";}}
	else { for (int i = 0; i < N; i++) { if (Massiv[i] != 0) fout << i << " "; } }
}