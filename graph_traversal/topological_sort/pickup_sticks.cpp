#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int n,m;
	while(1)
	{
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;
		vector< vector<int> > g;
		g.assign(n,vector<int>());

		int x,y;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			g[x-1].push_back(y-1);
		}

		vector<int> indegrees;
		indegrees.assign(n,0);

		for(int i = 0; i < g.size(); i++)
		{
			for(int j = 0; j < g[i].size(); j++)
			{
				indegrees[g[i][j]]++;
			}
		}

		queue<int> q;
		for(int i = 0; i < indegrees.size(); i++)
			if( indegrees[i] == 0)
				q.push(i);
		vector<int> ans;
		while( !q.empty())
		{
			int a = q.front();
			ans.push_back(a);
			q.pop();
			for(int i = 0; i < g[a].size(); i++)
			{
				indegrees[g[a][i]]--;
				if( indegrees[g[a][i]] == 0)
					q.push(g[a][i]);
			}
		}

		if( ans.size() != n)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			for(int i = 0; i < ans.size(); i++)
				cout << ans[i] + 1 << endl;
		}
	}
	return 0;
}


