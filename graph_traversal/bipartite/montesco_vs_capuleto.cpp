#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int bfs(vector< vector<int> >g,int u, vector<int>& color)
{
	queue<int> q;
	q.push(u);
	color[u] = 0;
	int total = 0;
	int black = 0;
	int f = 0;

	while( !q.empty())
	{
		int x = q.front();
		q.pop();

		total++;
		if( color[x] == 0)
			black++;
		for(int i = 0 ;i < g[x].size(); i++)
		{
			if( color[g[x][i]] == -1)
			{
				color[g[x][i]] = 1 - color[x];
				q.push(g[x][i]);
			}
			else if ( color[g[x][i]] == color[x])
				f  = 1;
		}
	}
	if ( f == 1) return 0;
	if( total == 1) return 1;
	return max(black, total - black) ;
}

int main()
{
	int t;
	cin >> t;
	vector<int> collect;
	while(t--)
	{
		vector< vector<int> > g;
		int n;
		cin >> n;
		int f = 0;
		g.assign(n,vector<int>());

		int k,x;
		int lone = 0;

		for(int i = 0; i < n; i++)
		{
			cin >> k;
			for(int j = 0; j < k; j++)
			{
				cin >> x;
				if ( x >= 1 && x <= n)
				{
					g[i].push_back(x-1);
					g[x-1].push_back(i);
				}
			}
		}

		vector<int> color;
		for(int i = 0; i < n; i++)
			color.push_back(-1);

		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			if( color[i] == -1)
			{
				int p = bfs(g,i,color);
				ans += p;
			}	
		}
		collect.push_back(ans);
	}
	for(int i = 0; i< collect.size(); i++)
		cout << collect[i] << endl;
	return 0;
}

