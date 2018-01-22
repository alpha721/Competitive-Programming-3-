#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if( n == 0)
			break;
		vector<string> v;
		vector<int> flag;
		flag.assign(n,0);
		v.assign(n,"");
		string a,b;
		
		int k = 0;
		for(int i = 0; i< n; i++)
		{
			cin >> a >> b;
			int x = b.size(); 
			while(x)
			{
				if( flag[k] == 0)
					x--;
				k++;
				if( k >= n) k = 0;
			}
			v[(k-1+n)%n] = a;
			flag[(k-1 + n)%n] = 1;
		}
		cout << v[0];
		for(int i = 1; i < v.size(); i++)
			cout << " " <<  v[i];
		cout << endl;
	}
	return 0;
}

