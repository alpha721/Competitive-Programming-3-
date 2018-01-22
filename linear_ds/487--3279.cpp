#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<char,int> mp;

int main()
{
	int t;
	cin >> t;
	char c = 'A';
	for(int i = 2; i < 10; i++)
	{
		if( c == 'Q') c++;
		mp.insert(make_pair(c,i));
		c++;
		if( c == 'Q') c++;
		mp.insert(make_pair(c,i));
		c++;
		if( c == 'Q') c++;
		mp.insert(make_pair(c,i));
		c++;
		if( c == 'Q') c++;
	}
	while(t--)
	{
		int n;
		cin >> n;



