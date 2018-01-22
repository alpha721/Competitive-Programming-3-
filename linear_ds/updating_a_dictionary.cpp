#include<iostream>
#include<map>
#include<vector>
#include<stdio.h>

using namespace std;

vector<string> split(string s,string x)
{
	int i = 0;
	vector<string> tokens;
	while(1)
	{
		int k = s.find(x,i);
		string a;
		if( k == string::npos)
		{
			a = s.substr(i);
			tokens.push_back(a);
			break;
		}
		a = s.substr(i,k-i);
		tokens.push_back(a);
		i = k + 1;
	}
	return tokens;
}

int main()
{
	int t;
	cin >> t;
	getchar();
	while(t--)
	{
		string a,b,x,y;
		getline(cin,a);
		x = a.substr(1,a.size()-2);
		getline(cin,b);
		y = b.substr(1,b.size()-2);
		vector<string> tokens_a = split(x,",");
		vector<string> tokens_b = split(y,",");
		map<string,string> mp_a;
		map<string,string> mp_b;

		for(int i = 0; i < tokens_a.size(); i++)
		{
			string z = tokens_a[i];
			int p = z.find(":");
			string first,second;
			first = z.substr(0,p);
			second = z.substr(p+1);
			mp_a.insert(make_pair(first,second));
		}

		for(int i = 0; i < tokens_b.size(); i++)
		{
			string z = tokens_b[i];
			int p = z.find(":");
			string first,second;
			first = z.substr(0,p);
			second = z.substr(p+1);
			mp_b.insert(make_pair(first,second));
		}

		vector<string> added;
		vector<string> changed;
		vector<string> del;
		map<string,string>::iterator it;

		for(it = mp_b.begin(); it != mp_b.end(); it++)
		{
			string first,second;
			first = it->first;
			second = it->second;
			if( mp_a.count(first) == 0 && first != "")
			{
				if( added.size() == 0)
					added.push_back("+"+first);
				else added.push_back(first);
			}
			else if( mp_a[first] != second && first != "")
			{
				if( changed.size() == 0)
					changed.push_back("*"+first);
				else changed.push_back(first);
			}
		}
		
		for(it = mp_a.begin(); it != mp_a.end(); it++)
		{
			string first,second;
			first = it->first;
			second = it->second;
			if( mp_b.count(first) == 0 && first != "")
			{
				if( del.size() == 0)
					del.push_back("-"+first);
				else del.push_back(first);
			}
		}
		
		if( changed.size() == 0 && added.size() == 0 && del.size() == 0)
			cout << "No changes" << endl;
		if(added.size() > 0)
		{
			
			for(int i = 0; i < added.size()-1; i++)
			{
				cout << added[i] << ",";
			}
			cout << added[added.size()-1] << endl;
		}
		if( del.size() > 0)
        {
		    for(int i = 0; i < del.size()-1; i++)
		    {
	          cout << del[i] << ",";
		    }
			cout << del[del.size()-1] << endl;
	    }
		if( changed.size() > 0)
		{
			for(int i = 0; i < changed.size() -1 ; i++)
			{
				cout << changed[i] << ",";
			}
			cout << changed[changed.size()-1] << endl;
		}
		cout << endl;		
	}
	return 0;
}
		
		
		

