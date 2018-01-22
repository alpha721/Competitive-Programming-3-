#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

vector< vector<int> >g;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;
int counter = 0;
int root;
int children = 0;
vector<int> articulation;
vector<int> ans;
vector< vector<string> > collect;

void dfs(int u)
{
	dfs_low[u] = dfs_num[u] = counter++;

	for(int i = 0; i < g[u].size(); i++)
	{
		if( dfs_num[g[u][i]] == -1)
		{
			parent[g[u][i]] = u;
			if( u == root) children++;
			dfs(g[u][i]);
			if( dfs_low[g[u][i]] >= dfs_num[u])
				articulation[u] = 1;
			dfs_low[u] = min( dfs_low[u], dfs_low[g[u][i]]);
		}
		else if( g[u][i] != parent[u])
		{
			dfs_low[u] = min( dfs_low[u], dfs_num[g[u][i]]);
		}
	}
}

int main()
{
	int n,m;
	while(1)
	{
		cin >> n;
		if( n == 0)
			break;
		map<string,int> mp;
		map<int,string> smp;

		string s;

		g.assign(n,vector<int>());
		dfs_num.assign(n,-1);
		dfs_low.assign(n,-1);
		parent.assign(n,-1);
		articulation.assign(n,0);

		for(int i = 0; i < n; i++)
		{
			cin >> s;
			mp.insert(make_pair(s,i));
			smp.insert(make_pair(i,s));
		}

		cin >> m;

		string a,b;
		for(int i = 0; i < m;  i++)
		{
			cin >> a >> b;
			int x = mp[a];
			int y = mp[b];
			
			g[x].push_back(y);
			g[y].push_back(x);
		}

		counter = 0;
		for(int i = 0; i < n; i++)
		{
			if( dfs_num[i] == -1)
			{
				root = i;
				children = 0;
				dfs(i);
				articulation[root] = ( children > 1);
			}
		}

		int total = 0;
		vector<string> temp;
		for(int i = 0; i < n; i++)
		{
			if( articulation[i] == 1)
			{
				total++;
				temp.push_back(smp[i]);
			}
		}

		ans.push_back(total);
		collect.push_back(temp);

		for(int i = 0; i < g.size(); i++)
			g[i].clear();
		articulation.clear();
		dfs_num.clear();
		dfs_low.clear();
		parent.clear();
	}
	string p = "City map #";
	string q = " camera(s) found";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << p << i+1 << ": " << ans[i] << q << endl;
		sort(collect[i].begin(), collect[i].end());
		for(int j  = 0; j < collect[i].size(); j++)
			cout << collect[i][j] << endl;
//		if( i < ans.size())
			cout << endl;
	}

	return 0;
}

