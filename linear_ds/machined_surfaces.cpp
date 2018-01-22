#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
#include<stdio.h>

using namespace std;

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if(  n == 0)
			break;
		vector<string> v;
		vector<int> size;
		string s;
		int x;
		int min = INT_MAX;
		getchar();
		for(int i = 0; i < n; i++)
		{
			getline(cin,s);
			int a = s.find_first_of(" ");
			int b = s.find_last_of(" ");
			if( a == -1 && b == -1)
				x = 0;
			else 
				x = b - a + 1;
			size.push_back(x);
			if( x < min)
				min = x;
		}

		int sum = 0;
		for(int i = 0; i < size.size();i++)
			sum += size[i] - min;

		cout << sum << endl;
	}
	return 0;
}	


