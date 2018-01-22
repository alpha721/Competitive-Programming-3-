#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

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
			return (( p[i] == i) ? i : find_set(p[i]));
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

vector< vector< pair<int,double> > > g;
vector<int> num_st;
vector<int> num_roads;
vector<int> num_rails;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,r;
		cin >> n >> r;
		vector<int> location_x;
		vector<int> location_y;
		vector< pair<double, pair<int,int> > > small_edges;
		vector< pair<double, pair<int,int> > > edges;

		g.assign(n,vector< pair<int,double> >());
		int x,y;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			location_x.push_back(x);
			location_y.push_back(y);
		}

		int states = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				double dx = (location_x[i] - location_x[j]) * ( location_x[i] - location_x[j]);
				double dy = (location_y[i] - location_y[j]) * ( location_y[i] - location_y[j]);

				double distance = sqrt(dx + dy);

				if( distance > 0)
				{
					g[i].push_back(make_pair(j,distance));
					g[j].push_back(make_pair(i,distance));
					edges.push_back(make_pair(distance, make_pair(i,j)));
				}
			}
		}

		sort(edges.begin(), edges.end());

		UnionFind UF(n);
		double roads = 0;
		double rails = 0;
		int sets = 1;
		for(int i = 0; i < edges.size(); i++)
		{
			pair< double, pair<int,int> > front = edges[i];

			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				if( front.first <= r)
					roads += front.first;
				else 
				{
					rails += front.first;
					sets++;
				}
				UF.union_set(front.second.first, front.second.second);
			}
		}

		for(int i = 0; i < g.size(); i++)
			g[i].clear();
		num_st.push_back(sets);
		num_roads.push_back(floor(roads + 0.5));
		num_rails.push_back(floor(rails + 0.5));
	}
	for(int i = 0; i < num_roads.size(); i++)
	{
		cout << "Case #" << i+1 << ": " << num_st[i] << " " << num_roads[i] << " " << num_rails[i] << endl;
	}

	return 0;
}


