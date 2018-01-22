#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		vector<bool> v;
		v.assign(n,false);

		int prev;
		int curr;
		int abs;
		for(int i = 0; i < n; i++)
		{
			cin >> curr;
			if( i >= 1)
			{
				if( curr > prev)
					abs = curr-prev;
				else 
					abs = prev - curr;
				prev = curr;
			}
			else prev = curr;
			if( abs - 1 < n && abs - 1 >= 0)
			v[abs-1] = true;
		}

		int f = 0;
		for(int i = 0; i < n-1; i++)
		{
			if( v[i] == false)
			{
				f = 1;
				break;
			}
		}

		if( f == 0)
			cout << "Jolly" << endl;
		else cout << "Not jolly" << endl;
	}
	return 0;
}
