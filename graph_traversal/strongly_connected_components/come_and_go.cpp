#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void tarjan(vector< vector<int> >g, int u, vector<int>& dfs_num, vector<int>& dfs_low, vector<int>& visited, stack<int>& s, int& counter, int& scc)
{
	dfs_num[u] = dfs_low[u] = counter++;
	visited[u] = 1;

	s.push(u);

	for(int i = 0;i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
			tarjan(g,g[u][i],dfs_num,dfs_low,visited,s,counter,scc);
		if( visited[g[u][i]])
		{
			dfs_low[u] = min( dfs_low[u], dfs_low[g[u][i]]);
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
		vector< vector<int> >g;
		g.assign(n,vector<int>());

		int x,y,w;

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> w;
			if( w == 1)
				g[x-1].push_back(y-1);
			else if ( w == 2)
			{
				g[x-1].push_back(y-1);
				g[y-1].push_back(x-1);
			}
		}

		vector<int> dfs_num;
		vector<int> dfs_low;
		vector<int> visited;

		int counter = 0;
		int scc = 0;
		stack<int> s;

		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		visited.assign(n,0);

		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
				tarjan(g,i,dfs_num,dfs_low,visited,s,counter,scc);
		}

		if( scc == 1)
			ans.push_back(1);
		else ans.push_back(0);
	}
	for(int i = 0; i < ans.size() ; i++)
		cout << ans[i] << endl;
	return 0;
}
