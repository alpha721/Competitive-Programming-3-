#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

void recurse(
int main()
{
	while(1)
	{
		string line;
		getline(cin,line);
		if( cin.eof())
			break;
		stringstream ss;

		ss(line);
		map<char,int> mp;
		map<char,int>::iterator it;

		int n = 0; 
		while(1)
		{
			char c;
			ss >> c;
			if( ss.eof())
				break;
			mp.insert(make_pair(c,n));
			n++;
		}

		n = mp.size();

		vector< vector<int> >g;
		g.assign(n , vector<int>());

		getline(cin,line);
		stringstream ssi;
		while(1)
		{
			char x,y;
			ssi >> x >> y;
			if( ssi.eof())
				break;
			int a = mp[x];
			int b = mp[y];
			
			g[a].push_back(b);
		}
		
		vector<int> indegree;

		set<int> free;

		for(int i = 0; i< n; i++)
			indegree.push_back(0);

		for(int i = 0; i < n; i++)
		{
			for(int j= 0; j < g[i].size(); j++)
				indegree[g[i][j]]++;
		}

		for(int i = 0; i < n; i++)
			if( indegree[i] == 0)
				free.insert(i);

		vector<int> result;
		recurse(free,indegree,g,result);
	}
	return 0;
}





		

