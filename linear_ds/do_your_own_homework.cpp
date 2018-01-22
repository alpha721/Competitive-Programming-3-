#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++)
	{
		cout << "Case " << k << ": " ;
		int n;
		cin >> n;
		string a;
		int num;
		map<string,int> mp;
		for(int i = 0; i < n; i++)
		{
			cin >> a >> num;
			mp.insert(make_pair(a,num));
		}
		int d;
		cin >> d;
		string sub;
		cin >> sub;

		if( mp.count(sub) == 0 || mp[sub] > d+5 )
			cout << "Do your own homework!" << endl;
		else if( mp[sub] > d  && mp[sub] <= d + 5)
			cout << "Late" << endl;
		else if( mp[sub] <= d)
			cout << "Yesss" << endl;
	}
	return 0;
}
