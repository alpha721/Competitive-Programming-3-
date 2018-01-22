#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool fun( pair< pair<string,string>, int> a, pair< pair<string,string>, int> b)
{
	if( a.first.second < b.first.second)
		return true;
	else if( a.first.second == b.first.second)
	{
		if( a.first.first < b.first.first)
			return true;
	}
	return false;
}

int main()
{
	vector< pair< pair<string,string>, int> > books;

	string s;
	while(1)
	{
		getline(cin,s);
		if( s == "END")
			break;
		int i = s.find('"',1);
		string title = s.substr(0,i+1);
		string author = s.substr(i+5);

		books.push_back(make_pair(make_pair(title,author),1));
	}

	sort(books.begin(), books.end(), fun);

	vector< pair< pair< string,string> , int> > returned;
	while(1)
	{
		string a,b;
		string str;
		getline(cin,str);
		a = str.substr(0,6);
		if( a == "SHELVE")
		{
			sort(returned.begin(), returned.end(),fun);
			for(int i = 0; i < returned.size(); i++)
			{
				string book = returned[i].first.first;
				int prev = -1;
				for(int j = 0; j < books.size(); j++)
				{
					if( books[j].first.first == book)
					{
						if( prev == -1)
							cout << "Put " << book << " first" << endl;
						else cout << "Put " << book << " after " << books[prev].first.first << endl;
					}
					else if( books[j].second == 1)
						prev = j;
				}
			}
			returned.clear();
			cout << "END" << endl;
		}
		else if( a == "END")
			break;
		else
		{
			b = str.substr(7);
			for(int i = 0; i < books.size(); i++)
			{
				if( books[i].first.first == b)
				{
					if( a == "BORROW")
						books[i].second = 0;
					else if( a == "RETURN")
					{
						books[i].second = 1;
						returned.push_back(books[i]);
					}
				}
			}
		}
	}	
	return 0;
}
