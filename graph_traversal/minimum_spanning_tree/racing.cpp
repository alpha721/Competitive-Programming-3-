#include<iostream>
#include<vector>
#include<algorithm>

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
			return ( (p[i] == i) ? i : find_set(p[i]));
		}

		bool is_same_set(int i,int j)
		{
			return ( find_set(i) == find_set(j));
		}

		void union_set(int i,int j)
		{
			if ( !is_same_set(i,j))
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
vector<int> ans;

bool fun( pair<int, pair<int,int> > a, pair<int, pair<int,int> > b)
{
	return ( a.first > b.first);
}

int main()
{
	int t;
	cin >> t;
	t++;
	while(t--)
	{
		int n,m;
		cin >> n;
		if( n == 0)
			break;
		cin	>> m;
	
		g.assign(n,vector< pair<int,int> >());
		vector< pair< int, pair<int,int> > > edges;

		int x,y,w;

		int total = 0;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> w;
			g[x-1].push_back(make_pair(y-1,w));
			g[y-1].push_back(make_pair(x-1,w));
			edges.push_back(make_pair(w, make_pair(x-1,y-1)));
			total += w;
		}

		UnionFind UF(n);
		sort(edges.begin(),edges.end(),fun);

		for(int i = 0; i < edges.size(); i++)
		{
			pair< int, pair<int,int> > front = edges[i];

			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				total -= front.first;
				UF.union_set(front.second.first, front.second.second);
			}
		}

		ans.push_back(total);
		for(int i =0; i < g.size(); i++)
			g[i].clear();
	}

	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}

