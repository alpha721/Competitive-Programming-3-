#include<iostream>
#include<vector>
#include<string>
#include<map>

int main()
{
	int test = 0;
	while(true)
	{
		test++;

		// read input

		string line;
		getline(cin,line);

		if( cin.eof())
			break;

		stringstream ss(line);
		vector<char> variables;

		char c;
		while( ss >> c)
		{
			variables.push_back(c);
		}

		sort(variables.begin(),variables.end());

		map<char,int> mp;
		vector< vector<int> > g;
		for(int i = 0; i < variables.size(); i++)
		{
			mp.insert(make_pair(variables[i],i));
		}

		int n = variables.size();

		g.assign(n, vector<int>());

		getline(cin,line);
		stringstream ss2(line);

		char a,b;
		while(1)
		{
			ss2 >> a >> b;
			if( ss2.eof())
				break;
			int x = mp[a];
			int y = mp[b];
			g[x].push_back(y);
		}


