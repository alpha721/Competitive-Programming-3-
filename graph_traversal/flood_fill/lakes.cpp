#include<iostream>
#include<vector>
#include<sstream>
#include<stdio.h>
using namespace std;

int dr[] = {1,1,1,0,-1,-1,-1,0};
int dc[] = {1,0,-1,-1,-1,0,1,1};
int floodfill(vector< vector<int> >&g, int r,int c,int x,int& count)
{
	if( r < 0 || r >= g.size() || c < 0 || c >= g[0].size())
		return 0;
	if( g[r][c] != x)
		return 0;
	count++;
	g[r][c] = -1;
	for(int i = 0; i < 8; i++)
		floodfill(g,r + dr[i], c + dc[i],x,count);
	return 1;
}

void read_input(int& x,int& y, vector< vector<int> >&g)
{
  string a,b;
  cin >> a;
  stringstream ss(a);
  cin >> b;
  stringstream ss1(b);

  ss >> x;
  ss1 >> y;
  string line;
  getchar();
  while(true)
  {
      getline(cin,line);
      if(line[0] == '1' || line[0] == '0')
	  {
	  	  
		 vector<int> temp;
		  for(int i = 0; i < line.size(); i++)
		  {
		       int x = line[i]-'0';
	          temp.push_back(x);
	      }
	      g.push_back(temp);
	  }
	  else break;
  }
  ss.str("");
  ss1.str("");
}

vector<int> collect;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
	  int x,y;
	  vector< vector<int> >g;
	  read_input(x,y,g);
	  int count = 0;
	  int ans = floodfill(g,x-1,y-1,0,count);
	  collect.push_back(count);
		
	}
	for(int i = 0; i < collect.size(); i++)
		cout << collect[i] << endl << endl;;
	return 0;
}
