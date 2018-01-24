#include<iostream>
#include<vector>
#include<stdio.h>
#include<sstream>
using namespace std;

int dr[] = {1,1,1,0,-1,-1,-1,0};
int dc[] = {1,0,-1,-1,-1,0,1,1};

int floodfill(vector< vector<char> >& g,int r,int c,char a,char b)
{
	if( r < 0 || r >= g.size() || c < 0 || c >= g[0].size())
		return 0;
	if( g[r][c] != a) return 0;
	g[r][c] = b;
	for(int i = 0; i < 8; i++)
	{
		floodfill(g,r + dr[i], c + dc[i], a,b);
	}
}

int main()
{
	while(1)
	{
		int n,m;
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;
		vector< vector<char> > g;
		char c;
		
		for(int i = 0; i < n; i++)
		{
			vector<char> temp;
			for(int j = 0; j < m; j++)
			{
				cin >> c;
				temp.push_back(c);
			}
			g.push_back(temp);
		}

		int ans = 0;
		for(int i= 0; i < g.size(); i++)
		{
			for(int j  = 0; j < g[i].size(); j++)
			{
				if( g[i][j] == '@')
				{
					ans++;
					int count = 0;
					floodfill(g,i,j,'@','*');
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}		
