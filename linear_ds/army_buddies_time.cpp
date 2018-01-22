#include<iostream>
#include<vector>

using namespace std;

int main()
{
	while(1)
	{
		int n,m;
		cin >> n >> m;
		if( n == 0 && m == 0)
			break;

		vector<int> v;
		v.assign(n,1);

		int x,y;
		for(int i = 0;i < m ;i++)
		{
			cin >> x >> y;
			for(int j = x-1; j < y; j++)
				v[j] = 0;
			int left = -1;
			int right = -1;
			for(int j = x-2; j >= 0; j--)
			{
				if( v[j] == 1)
				{
					left = j;
					break;
				}
			}

			for(int j = y; j < n; j++)
			{
				if( v[j] == 1)
				{
					right = j;
					break;
				}
			}

			if( left == -1 && right == -1)
				cout << "*" << " " << "*" << endl;
			else if( left == -1)
				cout << "*" << " " << right+1  << endl;
			else if( right == -1)
				cout << left + 1 << " " << "*" << endl;
			else cout << left + 1 << " " << right + 1  << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}


