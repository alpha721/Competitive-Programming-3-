#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

class UnionFind{
	private:
		vector<int> p;
		vector<int> rank;
		vector<int> set_size;

	public:
		int num_sets;

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
vector< pair<int,int> > ans;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		g.assign(n, vector< pair<int,int> >());
		vector< pair< int , pair<int,int> > > edges;
		vector< pair< int, pair<int,int> > > mst_edges;

		int x,y,w;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> w;
			g[x-1].push_back(make_pair(y-1,w));
			g[y-1].push_back(make_pair(x-1,w));
			edges.push_back( make_pair( w, make_pair(x-1,y-1)));
		}
		UnionFind UF(n);
		sort( edges.begin(), edges.end());

		int mst_cost = 0;
		for(int i = 0; i < edges.size(); i++)
		{
			pair< int, pair<int,int> > front = edges[i];
			
			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				mst_cost += front.first;
				UF.union_set(front.second.first, front.second.second);
				mst_edges.push_back(front);
			}
		}

		int second_mst = INT_MAX;
		int max_cost = 0;
		for(int i = 0; i < mst_edges.size(); i++)
		{
			UnionFind UFO(n);
			int k = 0;
			int f = 0;
			max_cost = 0;
			for(int j = 0; j < edges.size(); j++)
			{
				pair<int , pair<int,int> > front = edges[j];
				if( front == mst_edges[i] && k == 0)
					k = 1;
				else
				{
					if( !UFO.is_same_set(front.second.first , front.second.second))
					{
						max_cost += front.first;
						UFO.union_set(front.second.first, front.second.second);
					}
				}

				if( UFO.num_sets == 1)
				{
					f = 1;
					if( max_cost < second_mst)
						second_mst = max_cost;
				}
			}
		}
		ans.push_back(make_pair(mst_cost, second_mst));
	}

	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}
