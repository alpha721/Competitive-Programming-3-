#include<iostream>
#include<vector>
using namespace std;

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if( n == 0)
			break;
		vector<int> v;
		v.assign(n,-1);
		int x , y;
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v[i+y] = x;
		}

		int f= 0;
		for(int i = 0; i< v.size(); i++)
		{
			if( v[i] == -1)
			{
				f = 1;
				break;
			}
		}
		if( f == 0)
		{
			cout << v[0];
			for(int i = 1; i < n; i++)
				cout << " " << v[i];
			cout << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}


