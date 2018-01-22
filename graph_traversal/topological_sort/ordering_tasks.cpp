#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void topological(vector< vector<int> >g,int u, vector<int>& visited, stack<int>& s)
{
	visited[u] = 1;

	for(int i = 0; i < g[u].size(); i++)
	{
		if( visited[g[u][i]] == 0)
			topological(g,g[u][i],visited,s);
	}

	s.push(u);
}

int main()
{
	vector< vector<int> > v;
	while(1)
	{
		int n,m;

		cin >> n >> m;
		if( n == 0 && m == 0)
		 break;

		vector< vector<int> >g;
		g.assign(n,vector<int>());
		
		int x,y;
		
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			g[x-1].push_back(y-1);
		}

		vector<int> visited;
		for(int i = 0; i < n; i++)
			visited.push_back(0);

		stack<int> s;
		for(int i = 0; i < n; i++)
		{
			if( visited[i] == 0)
				topological(g,i,visited,s);
		}

		vector<int> temp;
		while( !s.empty())
		{
			int x = s.top();
			s.pop();
			temp.push_back(x+1);
		}
		v.push_back(temp);
	}
	for(int i = 0; i < v.size(); i++)
	{
		for(int j = 0; j < v[i].size() - 1; j++)
			cout << v[i][j] << " ";
		cout << v[i][v[i].size()-1];
		cout << endl;
	}

	return 0;
}	
