#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

vector< vector<int> >g;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
vector< vector< pair<int,int> > > ans;
vector< pair<int,int> > temp;

int counter = 0;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = counter++;

	for(int i = 0; i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
		{
			parent[g[u][i]] = u;
			dfs(g[u][i]);

			if(dfs_low[g[u][i]] > dfs_num[u])
			{
				if( u < g[u][i])
				temp.push_back(make_pair(u,g[u][i]));
				else 
				temp.push_back(make_pair(g[u][i],u));
			}
			dfs_low[u] = min( dfs_low[u], dfs_low[g[u][i]]);
		}
		else if ( g[u][i] != parent[u])
		{
			dfs_low[u] = min( dfs_low[u], dfs_num[g[u][i]]);
		}
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		g.assign(n,vector<int>());
		int m,a,b;
		string line;
		for(int i = 0; i < n; i++)
		{
			cin >> a;
			cin >> line;
			m = line[1] - '0';
			for(int j = 0; j < m; j++)
			{
				cin >> b;
				g[a].push_back(b);
				g[b].push_back(a);
			}
		}

		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		parent.assign(n,-1);

		counter = 0;
		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
				dfs(i);
		}
		ans.push_back(temp);

		for(int i = 0; i < g.size(); i++)
			g[i].clear();
		dfs_num.clear();
		dfs_low.clear();
		parent.clear();
		temp.clear();
	}
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].size() << " critical links" << endl;
		sort( ans[i].begin(), ans[i].end());
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j].first << " - " << ans[i][j].second << endl;
		}
		if( i < ans.size() - 1)
		cout << endl;
	}
	
	return 0;
}		
