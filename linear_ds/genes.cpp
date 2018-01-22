#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string,string> gene;
	map<string,string> father;
	map<string,string> mother;

	vector<string> child;
	string a,b;
	for(int i = 0;i < n; i++)
	{
		cin >> a >> b;
		if( b == "dominant" || b == "recessive" || b == "non-existent")
			gene.insert(make_pair(a,b));
		else
		{
			if( father.count(b))
			{
			   	mother.insert(make_pair(b,a));
				child.push_back(b);
			}
			else
				father.insert(make_pair(b,a));
		}
	}
	for(int i = 0; i < child.size(); i++)
	{
		string x = child[i];
		string gene_father = gene[father[x]];
		string gene_mother = gene[mother[x]];
		if( gene_father == "dominant" && gene_mother == "dominant")
			gene.insert(make_pair(x,"dominant"));
		else if( gene_father == "dominant" && gene_mother == "recessive")
			gene.insert(make_pair(x,"dominant"));
		else if ( gene_mother == "dominant" && gene_father == "recessive")
			gene.insert(make_pair(x,"dominant"));
	}

	map<string,string>::iterator it;
	for(it = gene.begin(); it != gene.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}

	
