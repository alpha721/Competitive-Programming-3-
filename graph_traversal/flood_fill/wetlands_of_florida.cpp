#include<iostream>
#include<vector>
#include<stdio.h>
#include<sstream>
using namespace std;

int dr[] = {1,1,1,0,-1,-1,-1,0};
int dc[] = {1,0,-1,-1,-1,0,1,1};

vector< vector<char> > g;
int floodfill(int r,int c,char a,char b,int& count)
{
	if( r < 0 || r >= g.size() || c < 0 || c >= g[0].size())
		return 0;
	if( g[r][c] != a) return 0;
	count++;
	g[r][c] = b;
	for(int i = 0; i < 8; i++)
	{
		floodfill(r + dr[i], c + dc[i], a,b,count);
	}
}

int main()
{
	int t;
	cin >> t;
	getchar();
	while(t--)
	{
		string s;
		while(true)
		{
			getline(cin,s);
			if( (s[0] == 'W' || s[0] == 'L'))
			{
				vector<char> temp;
				for(int i = 0; i < s.size(); i++)
				{
					temp.push_back(s[i]);
				}
				g.push_back(temp);
			}
			else break;
		}
		int a,b;
		string line;
		while( true)
		{
			stringstream ss(s);
			ss >> a >> b;
			int count = 0;
			floodfill(a-1,b-1,g[a-1][b-1],'.',count);
			cout << count << endl;
			ss.str("");
			getline(cin,s);
			if( s == "\n")
				break;
		}
	}
	return 0;
}

		
