#include<iostream>
#include<string>
#include<vector>
using namespace std;

void rev(string& s)
{
	int i = 0;
	int j = s.size()-1;
	while( i < j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
int main()
{
	while(1)
	{
		int n;
		cin >> n;
		if( n == 0)
			break;
		string s;
		cin >> s;
		int i = 0;
		int size = s.size()/n;
		string result = "";
		while( i < s.size())
		{
			string sub = s.substr(i,size);
			i += size;
			rev(sub);
			result += sub;
		}
		cout << result << endl;
	}
	return 0;
}



