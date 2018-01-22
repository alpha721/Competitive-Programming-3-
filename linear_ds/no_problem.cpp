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
		if( n < 0)
			break;
		cout << "Case " << t << ":" << endl;
		int available = n;
		vector<int> created;
		vector<int> required;
		int x;
		for(int i = 0; i < 12; i++)
		{
			cin >> x;
			created.push_back(x);
		}
	
		for(int i = 0; i < 12; i++)
		{
			cin >> x;
			required.push_back(x);
		}
	
		for(int i = 0; i < 12; i++)
		{
			if( available - required[i] < 0)
				cout << "No problem. :(" << endl;
			else
			{
				cout << "No problem! :D" << endl;
				available -= required[i];
			}
			available += created[i];
		}
		t++;
	}
	return 0;
}


