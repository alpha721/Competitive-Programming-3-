#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>

using namespace std;

int main()
{
	string first = "";
	string second = "";
	int n = 0;
	map<char,int> mp;
	map<char,int>::iterator it;
	vector< vector<int> >g;
	g.assign(20,vector<int>());
	while(1)
	{
		string s;
		cin >> s;
		if( s == "#")
			break;
		second = s;
		if(first == "")
		{
			first = second;
			continue;
		}

		int k = 0; 
		while( k < first.size() && k < second.size() && first[k] == second[k])
			k++;
		if( k == first.size() || k == second.size())
		{
			first = second;
			continue;
		}
		char x = first[k];
		mp.insert(make_pair(x,n));
		int a = n;
		n++;
		char y = second[k];
		mp.insert(make_pair(y,n));
		int b = n;
		n++;
		g[a].push_back(b);

		first = second;
	}
	vector<int> indegree;
	n = n-2;	
	for(int i = 0; i < n; i++)
		indegree.push_back(0);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < g[i].size(); j++)
			indegree[g[i][j]]++;
	}

	queue<int> q;
	set<char> st;
	string ans = "";
	while(1)
	{
		int f = 0;
		for(int i = 0; i < indegree.size(); i++)
		{
			if( indegree[i] == 0)
			{
				q.push(i);
				f = 1;
				break;
			}
		}
		if( f == 0)
			break;

		
		while( !q.empty())
		{
			int x = q.front();
			q.pop();

			char p;
			for(it = mp.begin(); it != mp.end(); it++)
			{
				if( it->second == x)
					p = it->first;
			}

			for(int i = 0; i < g[x].size() ; i++)
				indegree[g[x][i]]--;

			indegree[x] = -1;
			//if( st.count(p) == 0)
			//{
				ans.push_back(p);
			//	st.insert(p);
			//}
		}
	}
	
	cout << ans << endl;
	return 0;
}	
