#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Implementing Kruskal algorithm 

// Using union find data structure

class UnionFind{
	private:
		vector<int> p;
		vector<int> rank;
		vector<int> set_size;
		int num_sets;

	public:

		UnionFind(int N)
		{
			set_size.assign(N,1);
			num_sets = N;
			rank.assign(N,0);
			p.assign(N,0);
			for(int i = 0; i < N; i++)
				p[i] = i;
		}

		int find_set(int i)
		{
			return ((p[i] == i) ? i : find_set(p[i]));
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
			// rank is used to keep the tree short

				if( rank[x] > rank[y])
				{
					p[y] = x;
					set_size[x] += set_size[y];
				}
				else
				{
					p[x] = y;
					set_size[y] += set_size[x];
					if ( rank[x] == rank[y])
						rank[y]++;
				}
			}
		}

		int num_disjoint_sets() { return num_sets; }
		int size_of_sets(int i){ return set_size[find_set(i)]; }
}

int main()
{
	int n,m;

	vector< vector< pair<int,int> > >g;
	cin >> n >> m;
	g.assign(n,vector< pair<int,int> >());

	vector< pair<int, pair<int,int> > > edges;

	int x,y,w;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		g[x].push_back(make_pair(y,w));
		g[y].push_back(make_pair(x,w));
		edges.push_back(w,make_pair(x,y));
	}
	
	sort( edges.begin(), edges.end());

	int mst_cost = 0;

	UnionFind uf(V);

	for(int i = 0; i < E; i++)
	{
		pair<int, pair<int,int> > front = edges[i];
		if( !UF.is_same_set(front.second.first,front.second.second))
		{
			mst_cost += front.first;
			UF.union_set(front.second.first, front.second.second);
		}
	}

	cout << mst_cost << endl;
	return 0;
}

