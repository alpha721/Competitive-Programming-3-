#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int t = 1;
	while(1)
	{
		int n;
		cin >> n;
		if( n == 0)
			break;

		vector<int> v;
		int x;
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
			sum += x;
		}

		sum = sum/n;
		int total = 0;
		for(int i = 0; i < v.size(); i++)
		{
			if( v[i] > sum)
			   total += v[i] - sum;
			else total += sum - v[i];
		}

		cout << "Set #" << t << endl;
		cout << "The minimum number of moves is " << total/2 << "." << endl;
		t++;
		cout << endl;
	}
	return 0;
}	

