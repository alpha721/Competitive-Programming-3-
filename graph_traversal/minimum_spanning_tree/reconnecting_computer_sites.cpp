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
			return ( (p[i] == i) ? i : (find_set(p[i])));
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
vector< pair<int, pair<int,int> > > edges;
vector< pair<int, pair<int,int> > > temp_edges;
vector< pair<int,int> > ans;

int main()
{
	int n;
	while( cin >> n)
	{
		int x,y,w;
		g.assign(n,vector< pair<int,int> >());
		for(int i = 0; i < n-1; i++)
		{
			cin >> x >> y >> w;
		}
		int k;
		cin >> k;
		for(int i = 0; i < k; i++)
		{
			cin >> x >> y >> w;
			g[x-1].push_back(make_pair(y-1,w));
			g[y-1].push_back(make_pair(x-1,w));
			edges.push_back(make_pair(w, make_pair(x-1,y-1)));
		}

		int m;
		cin >> m;
		for(int i = 0; i < m; i++ ) 
		{
			cin >> x >> y >> w;
			g[x-1].push_back(make_pair(y-1,w));
			g[y-1].push_back(make_pair(x-1,w));
			edges.push_back( make_pair(w, make_pair(x-1,y-1)));
			temp_edges.push_back( make_pair( w, make_pair(x-1,y-1)));
		}

		sort( edges.begin(), edges.end());
		sort( temp_edges.begin(), temp_edges.end());

		UnionFind UF(n);
		UnionFind UFO(n);

		int first_mst_cost = 0;

		for(int i = 0; i < m; i++)
		{
			pair< int, pair<int,int> > front = temp_edges[i];
			
			if(!UF.is_same_set( front.second.first, front.second.second))
			{
				first_mst_cost += front.first;
				UF.union_set( front.second.first, front.second.second);
			}
		}	

		int second_mst_cost = 0;
		for(int i = 0; i < m+k; i++)
		{
			pair< int, pair<int,int> >front = edges[i];
			if( !UFO.is_same_set( front.second.first, front.second.second))
			{
				second_mst_cost += front.first;
				UFO.union_set( front.second.first, front.second.second);
			}
		}

		ans.push_back(make_pair(first_mst_cost,second_mst_cost));
		
		edges.clear();
		temp_edges.clear();

		for(int i = 0; i < g.size() ; i++)
		{
			g[i].clear();
		}
	}

	cout << ans[0].first << endl;
	cout << ans[0].second << endl;

	for(int i = 1; i < ans.size();  i++)
	{
		cout << endl;
		cout << ans[i].first << endl;
		cout << ans[i].second << endl;
	}
	return 0;
}


			







