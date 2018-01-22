#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector< vector<int> >g)
{
	vector<int> visited;
	vector<int> color;
	for(int i = 0;  i < g.size(); i++)
	{
		visited.push_back(0);
		color.push_back(-1);
	}

	queue<int> q;
	q.push(0);
	color[0] = 0;

	while( !q.empty())
	{
		int x = q.front();
		q.pop();
		visited[x] = 1;

		for(int i = 0; i < g[x].size(); i++)
		{
			if( visited[g[x][i]] == 0)
			{
				color[g[x][i]] = 1 - color[x];
				q.push(g[x][i]);
			}
			else if ( visited[g[x][i]] == 1)
			{
				if ( color[g[x][i]] == color[x])
				{
					cout << "NOT BICOLORABLE." << endl;
					return ;
				}
			}
		}
	}
	cout << "BICOLORABLE." << endl;
}

int main()
{
	while(1)
	{
		int n,m;
		cin >> n;
		if( n == 0)
			break;
		cin >> m;
		
		vector< vector<int> >g;

		g.assign(n,vector<int>());

		int x,y;
		for(int i = 0; i < m ; i++)
		{
			cin >> x >> y;
			g[x].push_back(y);
			g[y].push_back(x);
		}

		bfs(g);
	}
	return 0;
}

