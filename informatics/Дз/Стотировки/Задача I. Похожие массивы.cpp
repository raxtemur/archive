#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
 
ifstream fin("input.txt");
ofstream fout("output.txt");
vector<int> vec1, vec2;
vector<int>::iterator it;

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
		if ( *it != a)
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
