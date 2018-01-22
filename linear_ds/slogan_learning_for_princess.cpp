#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string a,b;
	map<string,string> mp;
	getchar();
	for(int i = 0; i < n; i++)
	{
		getline(cin,a);
		getline(cin,b);
		mp.insert(make_pair(a,b));
	}

	int m;
	cin >> m;
	string x;

	getchar();
	for(int i = 0; i < m; i++)
	{
		getline(cin,x);
		cout << mp[x] << endl;
	}

	return 0;
}

