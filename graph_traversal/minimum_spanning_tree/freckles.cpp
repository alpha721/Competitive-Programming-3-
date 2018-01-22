#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>

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
			return ( ( p[i] == i) ? i : find_set(p[i]));
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
vector<double> ans;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<double> position_x;
		vector<double> position_y;

		double x,y;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			position_x.push_back(x);
			position_y.push_back(y);
		}

		g.assign(n,vector< pair<int,double> >());
		vector< pair<double, pair<int,int> > > edges;

		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				double dx = (position_x[i] - position_x[j]) * (position_x[i] - position_x[j]);
				double dy = (position_y[i] - position_y[j]) * (position_y[i] - position_y[j]);

				double distance = sqrt(dx + dy);

				if( distance > 0)
				{
					g[i].push_back(make_pair(j,distance));
					g[j].push_back(make_pair(i,distance));
					edges.push_back(make_pair(distance, make_pair(i,j)));
				}
			}
		}

		sort(edges.begin(),edges.end());

		double mst_cost = 0;
		UnionFind UF(n);

		for(int i = 0; i < edges.size(); i++)
		{
			pair< double, pair<int,int> > front = edges[i];
			
			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				mst_cost += front.first;
				UF.union_set(front.second.first,front.second.second);
			}
		}

		ans.push_back(mst_cost);
		for(int i = 0; i < g.size(); i++)
			g[i].clear();
	}

	printf("%0.2f\n", ans[0]);
	for(int i = 1; i < ans.size(); i++)
	{
		cout << endl;
		printf("%0.2f\n", ans[i]);
	}

	return 0;
}

