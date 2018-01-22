#include<iostream>
#include<vector>
#include<sstream>
#include<stdio.h>

using namespace std;

vector< vector<int> >g;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
vector<int> articulation;
vector<int> ans;

int counter = 0;
int root;
int children = 0;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = counter++;
	
	for(int i = 0; i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
		{
			parent[g[u][i]] = u;
			if( u == root) children++;
			dfs(g[u][i]);

			if( dfs_low[g[u][i]] >= dfs_num[u])
				articulation[u] = 1;
			dfs_low[u] = min( dfs_low[u], dfs_low[g[u][i]]);
		}
		else if ( g[u][i] != parent[u])
		{
			dfs_low[u] = min( dfs_low[u] , dfs_num[g[u][i]]);
		}
	}
}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if( n == 0)
			break;
		g.assign(n,vector<int>());
		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		parent.assign(n,-1);
		articulation.assign(n,0);

		int a,b;
		getchar();
		while(1)
		{
			string line;
			getline(cin,line);
			stringstream ss(line);
			ss >> a;
			if( a == 0)
				break;
			while( ss >> b)
			{
				g[a-1].push_back(b-1);
				g[b-1].push_back(a-1);
			}
		}

		counter = 0;
		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
			{
				root = i;
				children = 0;
				dfs(i);
				articulation[root] = ( children > 1) ;
			}
		}

		int total = 0;
		for(int i = 0; i < n; i++)
		{
			if( articulation[i] == 1)
				total++;
		}
		ans.push_back(total);

		for(int i = 0; i < g.size(); i++)
		{
			g[i].clear();
		}
		articulation.clear();
		dfs_num.clear();
		dfs_low.clear();
		parent.clear();
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
			

				


