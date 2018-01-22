#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector< vector<int> >g, vector<int>& ans)
{
	vector<int> visited;
	vector<int> color;
	vector<int> component;

	for(int i = 0; i < g.size(); i++)
	{
		visited.push_back(0);
		color.push_back(-1);
	}

	queue<int> q;
	
	int black,white;
	for(int i = 0; i < g.size(); i++)
	{
		if( visited[i] == 0)
		{
			q.push(i);

			color[i] = 0;
		}
		while( !q.empty())
		{
			int x = q.front();
			q.pop();

			visited[x] = 1;
			
			for(int j = 0; j < g[x].size(); j++)
			{
				if( visited[g[x][j]] == 0)
				{
					color[g[x][j]] = 1 - color[x];
					q.push(g[x][j]);
				}
				else if ( visited[g[x][j]] == 1)
				{
					if ( color[g[x][j]] == color[x])
					{
						ans.push_back(-1);
						return ;
					}
				}
			}
		}
		for(int j = 0; j < color.size(); j++)
		{
		      if( color[j] == 0) white++;
		      else if ( color[j] == 1) black++;
		}
		if( black < white) component.push_back(black);
		else component.push_back(white);
		black = 0;
		white = 0;
	}
	int sum = 0;
	for(int i = 0; i < component.size(); i++)
		sum += component[i];
	ans.push_back(sum);

}


int main()
{
	int t;
	cin >> t;
	vector<int> ans;
	while(t--)
	{
		vector< vector<int> >g;
		int v,e;

		cin >> v >> e;
		g.assign(v,vector<int>());

		int x,y;
		for(int i = 0; i < e; i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		if( e == 0)
			ans.push_back(v);
		else bfs(g,ans);
	}
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}

