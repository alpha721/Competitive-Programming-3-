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
		vector<int> loop;
		int x;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			loop.push_back(x);
		}

		int peaks = 0;
		for(int i = 0; i < n; i++)
		{
			int prev,next;
			prev = i-1;
			next = i+1;
			if( i == 0)
				prev = n-1;
			else if( i == n-1)
				next = 0;
			if( loop[prev] < loop[i] && loop[next] < loop[i])
				peaks++;
			else if( loop[prev] > loop[i] && loop[next] > loop[i])
				peaks++;
		}

		cout << peaks << endl;
	}
	return 0;
}
