#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int bfs(vector< vector<int> >g,int u,vector<int>& color)
{
	color[u] = 0;

	queue<int> q;
	q.push(u);

	int total = 0;
	int black = 0;
	while( !q.empty())
	{
		int x = q.front();
		q.pop();
		total++;
		if( color[x] == 0)
			black++;

		for(int i = 0; i < g[x].size(); i++)
		{
			if( color[g[x][i]] == -1)
			{
				color[g[x][i]] = 1 - color[x];
				q.push(g[x][i]);
			}
			else if ( color[g[x][i]] == color[x])
			{
				return -1;
			}
		}
	}

	if( total == 1)
		return 1;
	else return min( black, total - black);
}

int main()
{
	int t;
	vector<int> collect;
	cin >> t;
	while(t--)
	{
		int v,e;
		int f = 0;
		cin >> v >> e;
		vector< vector<int> >g;

		g.assign(v,vector<int>());

		int x,y;
		for(int i = 0; i < e; i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		
		vector<int> color;
		for(int i = 0; i < v; i++)
			color.push_back(-1);

		int ans = 0;
		for(int i = 0; i < v; i++)
		{
			if( color[i] == -1)
			{
				int z = bfs(g,i,color);
				if( z == -1)
				{
					f = 1;
				}
				else ans += z;
			}
			
		}
		if( f == 1)
			collect.push_back(-1);
		else collect.push_back(ans);
	}

	for(int i = 0; i < collect.size(); i++)
		cout << collect[i] << endl;
	return 0;
}
