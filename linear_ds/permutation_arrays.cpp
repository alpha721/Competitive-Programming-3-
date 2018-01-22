#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>


using namespace std;

int main()
{
	int t;
	cin >> t;
	string dummy;

	getline(cin,dummy);	
	while(t--)
	{
		string s;
		getline(cin,dummy);
		getline(cin,s);
		stringstream ss(s);
		string word;
		vector<string> first;
		while( ss >> word)
		{
			first.push_back(word);
		}
		vector<string> second;
		getline(cin,s);
		stringstream sst(s);

		while( sst >> word)
		{
			second.push_back(word);
		}
		/*for(int i = 0; i < first.size(); i++)
		{
			cin >> word;
			second.push_back(word);
		}
		*/

		//getline(cin,dummy);
		map<string,string> mp;
		for(int i  = 0; i < first.size(); i++)
		{
			mp.insert(make_pair(first[i],second[i]));
		}

		sort(first.begin(), first.end());
		for(int i = 0; i < first.size(); i++)
		{
		   cout << mp[first[i]] << endl;
		}
		if( t != 0)
			cout << endl;
		first.clear();
		second.clear();
	}
	return 0;
}
		


