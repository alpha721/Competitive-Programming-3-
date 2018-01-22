#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n,m;
		cin >> n >> m;

		vector<bool> coins;
		for(int i = 0; i < n; i++)
		{
			coins.push_back(false);
		}

		int x;
		string s;
		for(int i = 0; i < m; i++)
		{
			cin >> x;
			int y;
			vector<int> left;
			for(int i = 0; i < x; i++)
			{
				cin >> y;
				left.push_back(y-1);
			}

			vector<int> right;
			for(int i = 0; i < x; i++)
			{
				cin >> y;
				right.push_back(y-1);
			}
			cin >> s;
			if( s == "=")
			{
				for(int j = 0; j < x; j++)
				{
					coins[left[j]] = true;
					coins[right[j]] = true;
				}
			}
			else
			{
				for(int j = 0; j < n; j++)
				{
					int coin = j;
					int flag = 0;
					for(int k = 0; k < x; k++)
					{
						if( coin == left[k] || coin == right[k])
							flag = 1;
					}
					if( flag == 0)
						coins[j] = true;
				}
			}
		}

		int f = 0;
		int fake = 0;
		for(int i = 0; i < n; i++)
		{
			if( coins[i] == false && f == 1)
				fake = 0;
			else if( coins[i] == false && f == 0)
			{
				f = 1;
				fake = i + 1;
			}
		}

		cout << fake << endl;
		if(t)
			cout << endl;
	}
	return 0;
}
