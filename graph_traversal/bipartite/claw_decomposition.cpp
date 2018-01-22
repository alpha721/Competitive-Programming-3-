#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int bfs(vector< vector<int> >g,int u, vector<int>& color)
{
	queue<int> q;
	q.push(u);
	color[u] = 0;

	while( !q.empty())
	{
		int x = q.front();
		q.pop();

		for(int i= 0; i < g[x].size(); i++)
		{
			if( color[g[x][i]] == -1)
			{
				color[g[x][i]] = 1 - color[x];
				q.push(g[x][i]);
			}
			else if ( color[g[x][i]] == color[x])
				return -1;
		}
	}
	return 0;
}


int main()
{
	while(1)
	{
		int v;
		cin >> v;
		if ( v == 0) break;

		int x,y;
		vector< vector<int> > g;
		g.assign(v,vector<int>());

		while(1)
		{
			cin >> x >> y;
			if( x == 0 && y == 0)
				break;
			g[x-1].push_back(y-1);
			g[y-1].push_back(x-1);
		}
		
		vector<int> color;
		for(int i = 0; i < v; i++)
			color.push_back(-1);

		int z,f = 0;
		for(int i = 0; i < v; i++)
		{
			if( color[i] == -1)
			{
				z =	bfs(g,i,color);
				if( z == -1)
					f = 1;
			}
		}
		if( f == 1)
			cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}


