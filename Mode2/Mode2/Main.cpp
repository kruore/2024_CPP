#include "iostream"
#include "map"
using namespace std;

int main()
{
	map<char, int> m;
	int n = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		if (m.find(s[i]) != m.end())
		{
			m[s[i]]++;
		}
		else
		{
			m.insert({ s[i] , 1 });
		}
	}
	s.clear();
	int B=0, S=0, A=0;
	for (auto item : m)
	{
		if (item.first == 'B')
		{
			B = item.second;
		}
		else if (item.first == 'S')
		{
			S = item.second;
		}
		else {
			A = item.second;
		}
	}
	if (B == S && B==A && A==S)
	{
		cout << "SCU" << endl;
	}
	else
	{
		for (auto item : m)
		{
			if (B == S)
			{

			}
		}
	}
}