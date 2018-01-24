#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int max_nodes;

int binary_search(int node,int balls)
{
	int left = node*2;
	int right = node* 2 + 1;
	if( left < max_nodes && right < max_nodes)
	{
		if( balls%2 == 0)
			binary_search(right,balls/2);
		else binary_search(left, balls/2 + 1);
	}
	else return node;
}

int main()
{
	int test ;
	cin >> test;
	while(1)
	{
		int d,k;
		cin >> d;
		if( d == -1)
			break;
		cin >> k;
		max_nodes = pow(2,d);
		int ans = binary_search(1,k);
		cout << ans << endl;
	}
	return 0;
}



