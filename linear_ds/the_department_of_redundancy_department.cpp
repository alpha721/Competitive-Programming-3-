#include<iostream>
#include<map>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
	string str;
	string s = "";
	while(	getline(cin,str))
	{
		s += str;
		s += " ";
	}
	stringstream ss(s);
	int word;
	map<int,int> mp;
	vector<int> v;
	int t  = 0;
	while( ss >> word)
	{
		if( mp.count(word) == 0)
		{
			mp.insert(make_pair(word,1));
			v.push_back(word);
		}
		else mp[word]++;
	}

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " " << mp[v[i]]  << endl;
	}
	return 0;
}
