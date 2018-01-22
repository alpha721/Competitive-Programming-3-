#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<stdio.h>
#include<algorithm>

using namespace std;

void tarjan( vector< vector<int> >g, int u , vector<int>& dfs_num, vector<int>& dfs_low, vector<int>& visited, stack<int>& s, int& counter, int& scc)
{
	dfs_num[u] = dfs_low[u] = counter++;

	visited[u] = 1;

	s.push(u);

	for(int i  = 0; i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
			tarjan(g,g[u][i],dfs_num,dfs_low,visited,s,counter,scc);
		if( visited[g[u][i]])
		{
			dfs_low[u] = min(dfs_low[u],dfs_low[g[u][i]]);
		}
	}

	if( dfs_low[u] == dfs_num[u])
	{
		scc++;
		while(1)
		{
			int v = s.top();
			s.pop();
			visited[v] = 0;
			if( u == v)
				break;
		}
	}
}


int main()
{
	vector<int> ans;
	while(1)
	{
		int n,m;
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;
		getchar();
		map<string,int> mp;
		vector< vector<int> >g;
		g.assign(n,vector<int>());

		string str;
		for(int i = 0; i < n; i++)
		{
			getline(cin,str);
			mp.insert(make_pair(str,i));
		}
//		getchar();
		for(int i = 0; i < m; i++)
		{
			string x,y;
			getline(cin,x);
			int a = mp[x];
			getline(cin,y);
			int b = mp[y];

			g[a].push_back(b);
		}

		vector<int> dfs_num;
		vector<int> dfs_low;
		vector<int> visited;

		stack<int> s;
		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		visited.assign(n,0);

		int counter = 0;
		int scc = 0;

		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
				tarjan(g,i,dfs_num,dfs_low,visited,s,counter,scc);
		}

		ans.push_back(scc);
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
