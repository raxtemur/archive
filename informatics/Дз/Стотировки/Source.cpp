#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vec1, vec2;
vector<int>::iterator it;

vector<int>::iterator lower_bound(vector<int>::iterator _begin, vector<int>::iterator _end, int _var)
{
	_end = _end - 1;
	vector<int>::iterator _place;
	if (_end - _begin > 1)
	{
		vector<int>::iterator _mid = _begin + (_end - _begin) / 2;
		if (_var > *_mid) _place = lower_bound(_mid + 1, _end + 1, _var);
		else _place = lower_bound(_begin, _mid + 1, _var);
		return (_place);
	}
	else /*return (_var == *_begin ? _begin : _end);*/
	{
		if (_var <= *_begin) return(_begin); 
		else return(_end);
	}
} //не знаю что такое map, но надеюсь, теперь все ќк.

vector<int> input()
{
	vector<int> Arr;
	int a, N;
	fin >> N;
	Arr.push_back(1000000000);
	for (size_t i = 1; i < N + 1; i++)
	{
		fin >> a;
		it = lower_bound(Arr.begin(), Arr.end(), a);
		if (*it != a)
		{
			Arr.insert(it, a);
		}
	}

	Arr.pop_back();
	return (Arr);
}

/*void print(vector<int> Arr)
{
for (int i = 0; i < Arr.size(); i++)
{
fout << Arr[i] << " ";
}
fout << endl;
}*/

int main()
{
	vec1 = input();
	vec2 = input();
	if (vec1 == vec2) { fout << "YES"; }
	else { fout << "NO"; }
	fin.close();
	fout.close();
}