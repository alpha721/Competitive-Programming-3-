#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

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

		int find_set(int i)
		{
			return ( ( p[i] == i) ? i : ( find_set(p[i])));
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
			
vector< vector< pair<int, int> > > g;
vector<int> ans;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n;
		g.assign(n, vector< pair<int,int> >());
		cin >> m;
		string a,b;
		map<string,int> mp;
		int w, c = 0;
		vector< pair<int, pair<int,int> > > edges;
		set<string> s;

		for(int i = 0; i < m; i++)
		{
			cin >> a >> b >> w;
			if( s.count(a) == 0)
			{
				mp.insert(make_pair(a,c));
				c++;
				s.insert(a);
			}

			if( s.count(b) == 0)
			{
				mp.insert(make_pair(b,c));
				c++;
				s.insert(b);
			}
			int x = mp[a];
			int y = mp[b];
			g[x].push_back(make_pair(y,w));
			g[y].push_back(make_pair(x,w));
			edges.push_back(make_pair(w, make_pair(x,y)));
		}

		UnionFind UF(n);
		int mst_cost = 0;
		sort( edges.begin(), edges.end());

		for(int i = 0; i < edges.size(); i++)
		{
			pair<int, pair<int,int> > front = edges[i];
				
			if( !UF.is_same_set(front.second.first,front.second.second))
			{
				mst_cost += front.first;
				UF.union_set(front.second.first, front.second.second);
			}
		}
		ans.push_back(mst_cost);

		for(int i = 0; i < n; i++)
			g[i].clear();
	}

	cout << ans[0] << endl;;
	for(int i = 1; i < ans.size(); i++)
		cout << endl << ans[i] << endl;

	return 0;
}


