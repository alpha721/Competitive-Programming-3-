#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main()
{
	int n;
	while( cin >> n)
	{
		vector<int> v;
		int x;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
		}

		sort(v.begin(),v.end());

		int total;
		cin >> total;

		vector<int> ::iterator low;
		vector< pair<int,int> > collect;
		int first,second,ans;
		for(int i = 0; i < v.size(); i++)
		{
			if ( total-v[i] > 0)
			{
				first = v[i];
				low = lower_bound(v.begin(),v.end(),total-v[i]);
				ans = low - v.begin();


				if( ans >= 0 && ans < v.size())
				{
					second = v[ans];
					collect.push_back(make_pair(first,second));
				}
			}
		}

		int min = INT_MAX;
		for(int i = 0; i < collect.size(); i++)
		{
			int diff = collect[i].first - collect[i].second;
			if( diff < 0)
				diff = -diff;
			if( diff < min)
			{
				min = diff;
				first = collect[i].first;
				second = collect[i].second;
			}
		}

		cout << "Peter should buy books whose prices are " <<first << " and " << second << "." << endl;
		cout << endl;
	}
	return 0;
}



