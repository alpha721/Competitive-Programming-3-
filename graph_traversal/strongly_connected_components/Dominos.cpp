#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector< vector<int> > get_transpose(vector< vector<int> >g)
{
	vector< vector<int> >trans;
	trans.assign(g.size(), vector<int>());
	
	for(int i = 0; i < g.size(); i++)
	{
		for(int j = 0; j < g[i].size(); j++)
		{
			trans[j].push_back(i);
		
		}
	}
	return trans;
}

	
void dfs(vector< vector<int> >g, int u, vector<int>& visited,stack<int>& s)
{
	visited[u] = 1;

	for(int i = 0; i < g[u].size(); i++)
	{
		if( visited[g[u][i]] == 0)
			dfs(g,g[u][i],visited,s);
	}
	s.push(u);
}

int main()
{
	vector<int> ans;
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
		stack<int> s;

		for(int i = 0; i < n; i++)
		{
			if( visited[i] == 0)
				dfs(g,i,visited,s);
		}

		vector< vector<int> >rev = get_transpose(g);
		for(int i = 0; i < n; i++)
			visited[i] = 0;

		int scc = 0;
		stack<int> dummy;
		while( !s.empty())
		{
			int v = s.top();
			s.pop();

			if( visited[v] == 0)
			{
				dfs(g,v,visited,dummy);
				scc++;
			}
		}
		ans.push_back(scc);
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
