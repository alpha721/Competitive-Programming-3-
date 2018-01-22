#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
	int test ;
	cin >> test;
	while(1)
	{
		int d,k;
		cin >> d;
		if( d == -1)
			break;
		cin >> k;
		int n = pow(2,d);
		
		vector<bool> v;
		v.assign(n,false);

		int ans = 0;
		for(int i = 0; i < k; i++)
		{
			int root = 1;
			int left = 2*root;
			int right = 2*root + 1;
			int t = 0;
			while(t < d)
			{
				if( v[root-1] == false)
				{
					v[root-1] = true;
					root = left;
				}
				else
				{
					v[root-1] = false;
					root = right;
				}
				left = 2*root;
				right = 2*root + 1;
				t++;
			}
			ans = root;
		}
		cout << ans/2 << endl;
	}
	return 0;
}



