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
		vector<int> left;
		vector<int> right;
		left.assign(n+1,0);
		right.assign(n+1,0);

		for(int i = 1; i <= n; i++)
		{
			left[i] = i-1;
			right[i] = i + 1;
		}
		left[1] = -1;
		right[n] = -1;
		int x,y;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			if( right[y] != -1)
				left[right[y]] = left[x];
			if( left[x] != -1)
				cout << left[x] << " ";
			else cout << "*" << " ";
			if( left[x] != -1)
				right[left[x]] = right[y];
			if( right[y] != -1)
				cout << right[y] << endl;
			else cout << "*" << endl;
		}
		cout << "-" << endl;
	}
	return 0;
}


