#include <fstream>
#include <vector>
#include <string>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vec;

int Pos = -1, Zn = 0, Sk = 0;

pair<int, int> TheChar(char ch) // first ->  ?? second -> pos
{
	pair<int, int> toReturn(-1, -1);

	if ((-1 < ch - '0') && (ch - '0' < 10))	toReturn = pair<int, int>(ch - '0', 1);

	if (ch == '(' || ch == ')')
	{
		if (ch == '(') { toReturn = pair<int, int>(1, 0); Sk = 1; }
		else { toReturn = pair<int, int>(-1, 0); Sk = -1;}
	}

	if (ch == '+' || ch == '-' || ch == '/' || ch == '*')	toReturn = pair<int, int>(0, 2);

	if (ch == ' ') toReturn = pair<int, int>(0, 0);

	if (toReturn == pair<int, int>(-1, -1))
	{

		Pos = 3;
		toReturn = pair<int, int>(0, 0);

	}
	return toReturn;
}

int main()
{
	pair<int, int> A;
	char a;
	string ss;
	getline(fin, ss);
	for (auto it = ss.begin(); it != ss.end(); it++)
	{
		a = *it;
		if (Pos == -1)
		{
			A = TheChar(a);
			if (A.first == 0 && A.second == 0) 1 + 1;
			else
			{
				if (A.second == 0 || A.second == 1)		Pos = A.second;
				else Pos = 3;
			}
		}

		else if (Pos == 0)
		{
			if (Sk == 1)
			{
				A = TheChar(a);
				if (A.first == 0 && A.second == 0) 1 + 1;
				else
				{
					if (A.second == 1 || (A.second == 0 && A.first == 1)) 
						Pos = A.second;
					else Pos = 3;
				}
			}
			else
			{
				A = TheChar(a);
				if (A.first == 0 && A.second == 0) 1 + 1;
				else
				{
					if (A.second == 2 || (A.second == 0 && A.first == -1)) 
						Pos = A.second;
					else Pos = 3;
				}
			}
		}

		else if (Pos == 1)
		{
			A = TheChar(a);
			if (A.first == 0 && A.second == 0) Pos = 4;
			else
			{
				if (A.second == 0 && A.first == 1) Pos = 3;
				else Pos = A.second;
			}

		}

		else if (Pos == 2)
		{
			A = TheChar(a);
			if (A.first == 0 && A.second == 0) 1 + 1;
			else
			{
				if (A.second == 1 || (A.second == 0 && A.first == 1)) Pos = A.second;
				else Pos = 3;
			}
		}

		else if (Pos == 4)
		{
			A = TheChar(a);
			if (A.first == 0 && A.second == 0) Pos = 4;
			else
			{
				if (A.second == 0 && A.first == 1 || A.second == 1) Pos = 3;
				else Pos = A.second;
			}
		}

		if (A.second == 0)
		{
			Zn += A.first;
			if (Zn < 0) Pos = 3;
		}
		if (Pos == 3) break;
	}
	if (Pos == 3 || Zn != 0 || Pos == 2) fout << "NO";
	else fout << "YES";
}