#include<iostream>
#include<vector>

using namespace std;

void dfs(vector< vector<int> >g, int u , vector<int>& visited)
{
	visited[u] = 1;
	for(int i = 0; i < g[u].size(); i++)
	{
		if( visited[g[u][i]] == 0)
			dfs(g,g[u][i],visited);
	}
}

int main()
{
//	vector<int> ans;
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		vector< vector<int> >g;
		g.assign(n,vector<int>());

		int x,y;

		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			g[x-1].push_back(y-1);
		}

		vector<int> visited;
		visited.assign(n,0);

		vector<int> topsort;

		for(int i = 0; i < n; i++)
		{
			if( visited[i] == 0)
			{
				dfs(g,i,visited);
				topsort.push_back(i);
			}
		}

		for(int i = 0; i < n; i++)
			visited[i] = 0;

		int scc = 0;
		for(int i = topsort.size() - 1; i >= 0; i--)
		{
			if( visited[topsort[i]] == 0)
			{
				dfs(g,topsort[i],visited);
				scc++;
			}
		}
		cout << scc << endl;
//		ans.push_back(scc);
	}
//	for(int i = 0; i < ans.size(); i++)
//		cout << ans[i] << endl;
	return 0;
}

