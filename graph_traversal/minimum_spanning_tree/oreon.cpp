#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<sstream>

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

		bool is_same_set(int i, int j)
		{
			return (find_set(i) == find_set(j));
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
vector< vector< pair< pair<char,char> ,int> > > ans;

bool fun(pair< pair<char,char> ,int> a, pair< pair<char,char> , int> b)
{
	if( a.second < b.second)
		return true;
	else if( a.second == b.second)
	{
		if( a.first.first < b.first.first)
			return true;
		else if( a.first.first == b.first.first)
		{
			if( a.first.second < b.first.second)
				return true;
		}
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		g.assign(n, vector< pair<int,int> >());
		vector< pair< int, pair<int,int> > > edges;
		
		getchar();
		for(int i = 0; i < n; i++)
		{
			string s;
			getline(cin,s);
			int j = 0;
			int x,y,w;
			x = i;
			int k = 0;
			int f = 0;
			while( k < s.size())
			{
				y = f;
				j = s.find(",",k);
				if( j == string::npos)
					break;
			
				stringstream ss;
				ss << s.substr(k,j-k);
				ss >> w;
				k = j + 2;
				//w = s[j]-'0';
				if( w > 0)
				{
					g[x].push_back( make_pair(y,w));
					g[y].push_back( make_pair(x,w));
					edges.push_back( make_pair(w, make_pair(x,y)));
				}
				f++;
				ss.str("");
			}
		}

		sort( edges.begin(), edges.end());
		vector< pair< pair<char,char>, int> > temp;
		UnionFind UF(n);

		for(int i = 0; i < edges.size(); i++)
		{
			pair< int, pair<int,int> > front = edges[i];

			if( !UF.is_same_set(front.second.first, front.second.second))
			{

				pair<char,char> char_pair;
				if( front.second.first < front.second.second)
					char_pair = make_pair((char)(front.second.first + 'A'), (char)(front.second.second + 'A'));
				else char_pair = make_pair((char)(front.second.second + 'A'), (char)(front.second.first + 'A'));;
				temp.push_back(make_pair(char_pair,front.first));
				UF.union_set(front.second.first, front.second.second);
			}
		}

		ans.push_back(temp);
		for(int i = 0; i < n; i++)
			g[i].clear();
	}

	
	for(int i = 0; i < ans.size() ; i++)
	{
		cout << "Case " << i+1 << ":" << endl;
		//sort(ans[i].begin(),ans[i].end());
		sort(ans[i].begin(),ans[i].end(),fun);
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j].first.first << "-" << ans[i][j].first.second << " " << ans[i][j].second << endl;
		}
	}

	return 0;
}

