#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<set>

using namespace std;

void tarjan(vector< vector<int> >g, int u, vector<int>& dfs_num, vector<int>& dfs_low, vector<int>& visited, stack<int>& s, int& counter, int& scc, map<string,int> mp, map<int,string> mt, vector<string>& temp )
{
	dfs_low[u] = dfs_num[u] = counter++;
	visited[u] = 1;
	s.push(u);

	for(int i = 0; i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
			tarjan(g,g[u][i],dfs_num,dfs_low,visited,s,counter,scc,mp,mt,temp);
		if( visited[g[u][i]] == 1)
		{
			dfs_low[u] = min(dfs_low[u], dfs_low[g[u][i]]);
		}
	}

	string add = "";
	if( dfs_low[u] == dfs_num[u])
	{
		scc++;
		while(1)
		{
			int v = s.top();
			s.pop();
			add += " ,";
			add += mt[v];
			visited[v] = 0;
			if( u == v)
				break;
		}
		add = add.substr(2);
		temp.push_back(add);
	}
}

int main()
{
	vector< vector<string> >ans;
	while(1)
	{
		int n,m;
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;
		vector< vector<int> >g;
		g.assign(n,vector<int>());
		set<string> set;
		map<string,int> mp;
		map<int,string> mt;
		vector<string> temp;
		string x,y;
		int k = 0;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			if( set.count(x) == 0)
			{	
				mp.insert(make_pair(x,k));
				mt.insert(make_pair(k,x));
				k++;
				set.insert(x);
			}
			if( set.count(y) == 0)
			{
				mp.insert(make_pair(y,k));
				mt.insert(make_pair(k,y));
				k++;
				set.insert(y);
			}

			int a = mp[x];
			int b = mp[y];
			g[a].push_back(b);
		}

		vector<int> dfs_num;
		vector<int> dfs_low;
		vector<int> visited;
		stack<int> s;

		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		visited.assign(n,0);

		int scc = 0;
		int counter = 0;

		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
				tarjan(g,i,dfs_num,dfs_low,visited,s,counter,scc,mp,mt,temp);
		}
		ans.push_back(temp);
	}
	for(int i = 0; i < ans.size(); i++)
	{
		cout << "Calling circles for data set " << i+1 << ":" << endl;
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << endl;
		cout << endl;
	}
	return 0;
}
