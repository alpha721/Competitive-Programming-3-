#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int test = 1;
	int n;
	while( cin >> n)
	{
		string s;
		map<string,int> mp;
		vector< vector<int> > g;
		g.assign(n,vector<int>());

		for(int i = 0; i < n; i++)
		{
			cin >> s;
			mp.insert(make_pair(s,i));
		}

		int m;
		cin >> m;
		string x,y;

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			int a = mp[x];
			int b = mp[y];
			g[a].push_back(b);
		}

		vector<int> indegree;
		indegree.assign(n,0);

		for(int i = 0; i < g.size(); i++)
		{
			for(int j = 0; j < g[i].size(); j++)
			{
				indegree[g[i][j]]++;
			}
		}

		queue<int> q;
		vector<string> ans;
		map<string,int>::iterator it;
		// this is also a fair topological sort but it doesn't work for this problem

		for(int i = 0; i < indegree.size(); i++)
		{
			if( indegree[i] == 0)
			{
				q.push(i);
			}
		}
		while( !q.empty())
		{
			int x = q.front();
			q.pop();
			for(it = mp.begin(); it != mp.end(); it++)
			{
				if( it->second == x)
				{
					ans.push_back(it->first);
					break;
				}
			}
			for(int i = 0; i < g[x].size(); i++)
			{
				indegree[g[x][i]]--;
				if( indegree[g[x][i]] == 0)
					q.push(g[x][i]);
			}
		}

		cout << "Case #" << test << ": Dilbert should drink beverages in this order: ";
		for(int i = 0; i < ans.size()-1; i++)
		{
			cout << ans[i] << " " ;
		}
		cout << ans[ans.size()-1] << "." << endl;
		cout << endl;
		test++;
	}
	return 0;
}
	



			


