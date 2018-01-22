#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

vector< vector<int> >g;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
vector<int> art;
int counter = 0;
int root,children;

void find_points(int u)
{
	dfs_low[u] = dfs_num[u] = counter++;

	for(int i = 0; i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
		{
			parent[g[u][i]] = u;
			if( u == root) 
				children++;
			find_points(g[u][i]);

			if( dfs_low[g[u][i]] >= dfs_num[u])
				art[u] = 1;
			dfs_low[u] = min( dfs_low[u],dfs_low[g[u][i]]);
		}
		else if ( g[u][i] != parent[u])
			dfs_low[u] = min( dfs_low[u],dfs_num[g[u][i]]);
	}
}


int main()
{
	vector<int> ans;
	
	while(1)
	{
		int n;
		cin >> n;
		if( n == 0)
			break;
		vector< vector<int> >g;
		g.assign(n,vector<int>());
		getchar();
		while(1)
		{
			string s;
			getline(cin,s);
			int x = s[0] - '0';
			if( x == 0)
				break;
			int y;
			int k = 2;
			while( k < s.size())
			{
				y = s[k] - '0';
				g[x-1].push_back(y-1);
				g[y-1].push_back(x-1);
				k += 2;
			}
		}

		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		parent.assign(n,-1);
		art.assign(n,0);
		counter = 0;
	
		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
			{
				root = i;
				children = 0;
				find_points(i);
				art[root] = (children > 1);
			}
		}
		int total = 0;

		for(int i = 0; i < n; i++)
		{
			if( art[i] == 1)
				total++;
		}

		ans.push_back(total);
		dfs_num.clear();
		dfs_low.clear();
		parent.clear();
		art.clear();
		//g.clear();
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
