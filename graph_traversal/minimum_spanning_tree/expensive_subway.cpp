#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class UnionFind{

	private:
		vector<int> p;
		vector<int> rank;
		vector<int> set_size;
		int num_sets;

	public:

		UnionFind(int N)
		{
			p.assign(N,0);
			rank.assign(N,0);
			set_size.assign(N,1);
			num_sets = N;

			for(int i = 0; i < N; i++)
				p[i] = i;
		}

		~UnionFind()
		{
			p.clear();
			rank.clear();
			set_size.clear();
		}

		int find_set(int i)
		{
			return ( (p[i] == i) ? i : find_set(p[i]));
		}

		bool is_same_set(int i,int j)
		{
			return ( find_set(i) == find_set(j));
		}

		void union_set(int i,int j)
		{
			if( !is_same_set(i,j))
			{
				num_sets--;
				int x = find_set(i);
				int y = find_set(j);

				if( rank[x] > rank[y])
				{
					p[y] = x;
					set_size[x] += set_size[y];
				}
				else
				{
					p[x] = y;
					set_size[y] += set_size[x];
					if( rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
};


vector< vector< pair<int,int> > > g;
vector< pair< int, pair<int,int> > > edges;
vector<int> visited;
vector<int> ans;

void dfs(int u)
{
	visited[u] = 1;
	for(int i = 0; i < g[u].size() ; i++)
	{
		if( visited[g[u][i].first] == 0)
			dfs(g[u][i].first);
	}
}

int main()
{
	int n,m;
	while(1)
	{
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;

		string s;
		map<string,int> mp;

		for(int i = 0;i < n ;i++)
		{
			cin >> s;
			mp.insert(make_pair(s,i));
		}

		g.assign(n,vector< pair<int,int> >());
		int x,y,w;
		string a, b;
		for(int i = 0; i < m; i++)
		{
			cin >> a >> b >> w;
			x = mp[a];
			y = mp[b];
			g[x].push_back(make_pair(y,w));
			g[y].push_back(make_pair(x,w));
			edges.push_back(make_pair(w, make_pair(x,y)));
		}

		cin >> s;
		int start = mp[s];

		visited.assign(n,0);

		dfs(start);

		int f = 0;
		for(int i = 0; i < visited.size(); i++)
		{
			if( visited[i] == 0)
			{
				ans.push_back(-1);
				f = 1;
				break;
			}
		}

		if( f == 1)
			continue;

		UnionFind UF(n);

		int cost = 0;
		sort(edges.begin(), edges.end());

		for(int i = 0; i < edges.size(); i++)
		{
			pair<int, pair<int,int> > front = edges[i];

			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				cost += front.first;
				UF.union_set(front.second.first, front.second.second);
			}
		}

		ans.push_back(cost);
		for(int i = 0; i < g.size(); i++)
			g[i].clear();
		visited.clear();
		edges.clear();
		UF.~UnionFind();
	}
	for(int i = 0; i < ans.size(); i++)
	{
		if( ans[i] == -1)
			cout << "Impossible" << endl;
		else cout << ans[i] << endl;
	}

	return 0;
}
