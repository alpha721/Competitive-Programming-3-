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
vector< vector<int> > ans;

int main()
{
	while(1)
	{
		int n,m;
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;
		g.assign(n,vector< pair<int,int> >());
		vector< pair<int, pair<int,int> > > edges;

		int x,y,w;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> w;
			g[x].push_back(make_pair(y,w));
			g[y].push_back(make_pair(x,w));
			edges.push_back(make_pair(w, make_pair(x,y)));
		}

		UnionFind UF(n);

		sort(edges.begin(), edges.end());
		vector<int> temp;

		for(int i = 0; i < edges.size(); i++)
		{
			pair<int, pair<int,int> > front = edges[i];

			if( !UF.is_same_set(front.second.first, front.second.second))
			{
				UF.union_set(front.second.first, front.second.second);
			}
			else
				temp.push_back(front.first);
		}

		sort(temp.begin(), temp.end());
		ans.push_back(temp);
		for(int i = 0; i < g.size(); i++)
			g[i].clear();
	}
	
	for(int i = 0; i < ans.size(); i++)
	{
		if( ans[i].size() == 0)
			cout << "forest" << endl;
		else
		{
			cout << ans[i][0];
			for(int j = 1; j < ans[i].size(); j++)
			{
				cout << " " <<  ans[i][j] ;
			}
			cout << endl;
		}
	}

	return 0;
}
	   	
