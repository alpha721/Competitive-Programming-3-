#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary_search(vector<int> marbles,int l,int r,int val)
{
	if( l <= r)
	{
		int mid = l + (r-l)/2;

		if( (mid == 0 && marbles[mid] == val)|| (marbles[mid] == val && marbles[mid-1] < val))
			return mid + 1;
		else if( marbles[mid] == val && marbles[mid -1] == val)
		{
			return binary_search(marbles,l,mid-1,val);
		}
		else if( marbles[mid] < val)
		{
			return binary_search(marbles,mid+1, r, val);
		}
		else if ( marbles[mid] > val)
		{
			return binary_search(marbles,l,mid-1,val);
		}
	}
	return -1;
}


int main()
{
	int t = 1;
	while(1)
	{
		int n,k;
		cin >> n >> k;
		if( n == 0 && k == 0)
			break;
		cout << "CASE# " << t << ":" << endl;
		t++;
		vector<int> marbles;

		int x;
		for(int i = 0;i < n; i++)
		{
			cin >> x;
			marbles.push_back(x);
		}

		sort(marbles.begin(),marbles.end());

		for(int i = 0; i < k; i++)
		{
			cin >> x;
			int ans = binary_search(marbles,0,marbles.size()-1,x);
			if( ans == -1)
				cout << x << " not found" << endl;
			else cout << x  << " found at " << ans << endl;
		}
	}
	return 0;
}
