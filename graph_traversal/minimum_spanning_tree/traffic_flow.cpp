#include<iostream>
#include<vector>
#include<algorithm>

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

			for(int i = 0; i < N ; i++)
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

		void union_set(int i, int j)
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
vector<int> ans;

bool fun(pair< int, pair<int,int> > a, pair<int, pair<int,int> > b)
{
	return (a.first > b.first);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		g.assign(n+1, vector< pair<int,int> >());
		vector< pair< int, pair<int,int> > > edges;

		int x,y,w;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> w;
			g[x].push_back(make_pair(y,w));
			g[y].push_back(make_pair(x,w));
			edges.push_back(make_pair(w, make_pair(x,y)));
		}
		sort(edges.begin(), edges.end(), fun);
		UnionFind UF(n);
		vector<int> temp;

		for(int i = 0; i < edges.size(); i++)
		{
			pair< int, pair<int,int> > front = edges[i];
			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				temp.push_back(front.first);
				UF.union_set(front.second.first, front.second.second);
			}
		}
		ans.push_back(temp.back());

		for(int i = 0; i < g.size(); i++)
			g[i].clear();
	}

	for(int i = 0 ; i < ans.size(); i++)
		cout << "Case #" << i+1 << ": " <<  ans[i] << endl;
	return 0;
}
