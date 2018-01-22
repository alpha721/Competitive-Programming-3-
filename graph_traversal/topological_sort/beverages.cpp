#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<queue>

using namespace std;

int main()
{
	int n;

	vector<string> v;
	int number = 1;
	while( scanf("%d",&n) == 1)
	{
		map<string,int> mp;
		map<string,int>::iterator it;
		string s;
		for(int i = 0; i < n; i++)
		{
			cin >> s;
			mp.insert(make_pair(s,i));
		}

		stringstream ss;
		int m;
		cin >> m;

		string x,y;
		vector< vector<int> >g;
		g.assign(n,vector<int>());

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			int a = mp[x];
			int b = mp[y];
			g[a].push_back(b);
		}

		vector<int> indegree;
		for(int i = 0; i < n; i++)
			indegree.push_back(0);

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < g[i].size(); j++)
			{
				indegree[g[i][j]]++;
			}
		}

		string digit;
		string first = "Case #";
	    string last = ": Dilbert should drink beverages in this order:";
		ss << number;
		ss >> digit;

		queue<int> q;
		string ans = first + digit + last;
		while(1)
		{
			int f = 0;
			for(int i = 0; i < n; i++)
			{
				if( indegree[i] == 0)
				{
					q.push(i);
					f = 1;
					break;
				}
			}
			if( f == 0)
				break;
			while(!q.empty())
			{
				int z = q.front();
				string p;
				q.pop();
				for(it = mp.begin(); it != mp.end(); it++)
				{
					if( it->second == z)
					{
						p = it->first;
						break;
					}
				}
				ans += " ";
				ans += p;
				for(int i = 0; i < g[z].size(); i++)
				indegree[g[z][i]]--;
				indegree[z] = -1;
			}
		}
		ans += ".";
		v.push_back(ans);
		number++;
	}
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl << endl;

	return 0;
}
