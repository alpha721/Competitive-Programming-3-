#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

int main()
{
	string s;
	map<char,int> mp;
	mp.insert(make_pair('B',1));
	mp.insert(make_pair('F',1));
	mp.insert(make_pair('P',1));
	mp.insert(make_pair('V',1));
	mp.insert(make_pair('C',2));
	mp.insert(make_pair('G',2));
	mp.insert(make_pair('J',2));
	mp.insert(make_pair('K',2));
	mp.insert(make_pair('Q',2));
	mp.insert(make_pair('S',2));
	mp.insert(make_pair('X',2));
	mp.insert(make_pair('Z',2));
	mp.insert(make_pair('D',3));
	mp.insert(make_pair('T',3));
	mp.insert(make_pair('L',4));
	mp.insert(make_pair('M',5));
	mp.insert(make_pair('N',5));
	mp.insert(make_pair('R',6));

	while( cin >> s)
	{
		int prev = -1;
		for(int i = 0; i < s.size(); i++)
		{
			
			if( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'H' || s[i] == 'W' || s[i] == 'Y')
			{
				prev = 0;
			}
			else
			{
				if( prev == -1 || prev != mp[s[i]])
				cout << mp[s[i]];
				prev = mp[s[i]];
			}
		}
		cout << endl;
	}

	return 0;
}

