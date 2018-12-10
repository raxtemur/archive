#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vec1, vec2;

vector<int> input(int N)
{
	vector<int> Arr(N);
	int a;
	for (size_t i = 0; i < N; i++)
	{
		fin >> a;
		Arr[i] = a;
	}
	return (Arr);
}

vector<int> Sliv(vector<int> vecArr, int L, int R)
{
	vector<int> Buffer;
	int x = 0;
	int a = L, b = (L + R) / 2 + 1;
	while ((a < (L + R) / 2 + 1) && (b < R + 1))
	{
		if (vecArr[a] < vecArr[b]) { Buffer.push_back(vecArr[a]); a++; }
		else { Buffer.push_back(vecArr[b]); b++; }
		x++;
	}
	if (a < (L + R) / 2 + 1) { for (size_t i = a; i < (L + R) / 2 + 1; i++) { Buffer.push_back(vecArr[i]); } }
	if (b < R + 1) { for (size_t i = b; i < R + 1; i++) { Buffer.push_back(vecArr[i]); } }
	for (size_t i = L, x = 0; i < R + 1; i++, x++) { vecArr[i] = Buffer[x]; }
	Buffer.clear();
	return(vecArr);
}

void vec1Sort(int L, int R)
{
	if (L != R)
	{
		vec1Sort(L, (L + R) / 2);
		vec1Sort((L + R) / 2 + 1, R);
		vec1 = Sliv(vec1, L, R);
	}
}

void vec2Sort(int L, int R)
{
	if (L != R)
	{
		vec2Sort(L, (L + R) / 2);
		vec2Sort((L + R) / 2 + 1, R);
		vec2 = Sliv(vec2, L, R);
	}
}

vector<int> SuperSort(vector<int> Arr)
{
	for (int k = 0; k < Arr.size() - 1; k++)
	{
		for (int i = 0; i < Arr.size() - 1; i++)
		{
			if (Arr[i] != Arr[i + 1])	{ if (Arr[i] > Arr[i + 1]) { swap(Arr[i], Arr[i + 1]); } }
			else { Arr.erase(Arr.begin() + i + 1); i--; }
		}
	}
	return(Arr);
}

/*void print(vector<int> Arr)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		fout << Arr[i] << " ";
	}
	fout << endl;
}*/

bool IsVec1LikeVec2()
{
	int count = 1, n = 0;
	for (size_t i = 0; i < vec1.size(); i++)
	{
		if ((i == vec1.size() - 1) || (vec1[i] != vec1[i + 1]))
		{
			for (size_t j = n;  j < vec2.size();  j++)
			{
				if ((j == vec2.size() - 1) || (vec2[j] != vec2[j + 1]))
				{
					n = j + 1;
					if (vec1[i] != vec2[j]) count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	return(count);
}

int main()
{
	int N;
	fin >> N;
	vec1 = input(N);
	vec1Sort(0, vec1.size() - 1);
	//print(vec1);
	fin >> N;
	vec2 = input(N);
	vec2Sort(0, vec2.size() - 1);
	//print(vec2);
	if (IsVec1LikeVec2()) { fout << "YES"; }
	else { fout << "NO"; }
}