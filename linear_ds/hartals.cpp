#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int p;
		cin >> p;

		vector<int> hartal;

		int x;
		for(int i = 0; i < p; i++)
		{
			cin >> x;
			hartal.push_back(x);
		}

		vector<bool> days;
		days.assign(n+1,false);
		for(int i = 0; i < p; i++)
		{
			int k = hartal[i];
			while( k <= n)
			{
				days[k] = true;
				k += hartal[i];
			}
		}

		int total = 0;
		int f = 6;
		for(int i = 1; i < days.size(); i++)
		{
			if( i == f)
			{
				days[i] = false;
				f += 7;
			}
			if( i%7 == 0)
				days[i] = false;
			if( days[i] == true)
				total++;
		}

		cout << total << endl;
	}
	return 0;
}
