#include<iostream>
#include<stack>
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
		while(1)
		{
			stack<int> s;
			for(int i = n; i >= 1; i--)
				s.push(i);
			stack<int> mid;
			vector<int> result;
			vector<int> input;
			int x;
			int f = 0;
			for(int i = 0; i < n; i++)
			{
				cin >> x;
				if( x == 0)
				{
					f = 1;
					break;
				}
				input.push_back(x);
			}
			if( f == 1)
				break;
			stack<int> in;
			for(int i = n-1; i >= 0 ;i--)
				in.push(input[i]);
			f = 0;
			while( !s.empty())
			{
				if( s.top() == in.top())
				{
					result.push_back(s.top());
					s.pop();
					in.pop();
				}
				else if( s.top() < in.top())
				{
					mid.push(s.top());
					s.pop();
				}
				else if( s.top() > in.top())
				{
					if( !mid.empty() && mid.top() == in.top())
					{
						while( !mid.empty() && mid.top() == in.top())
						{
							result.push_back(mid.top());
							mid.pop();
							in.pop();
						}
					}
					else 
					{
						f = 1;
						break;
					}
				}
			}
			while( !mid.empty())
			{
				result.push_back(mid.top());
				mid.pop();
			}
			for(int i = 0; i < n; i++)
			{
				if( result[i] != input[i])
				{
					f = 1;
					break;
				}
			}
			if( f == 0)
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
	return 0;
}




		
