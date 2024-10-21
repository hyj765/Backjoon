#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

vector<string> split(string str,char delimeter)
{

	stringstream ss(str);
	string buffer;
	vector<string> sr;

	while (std::getline(ss,buffer,delimeter))
	{
		sr.push_back(buffer);
	}

	return sr;
}


class Trie
{
public:
	Trie()
	{
	}

	void insert(vector<string> str)
	{
		Trie* trie = this;
		for (int i = 0; i < str.size(); ++i)
		{
			if (trie->subnodes.find(str[i]) == trie->subnodes.end())
			{
				trie->subnodes[str[i]] = new Trie();
			}
			trie = trie->subnodes[str[i]];
		}
	}

	void PrintKey(int depth)
	{
		Trie* root = this;
		
		for (auto sub : subnodes)
		{
			for (int i = 0; i < depth; ++i) printf(" ");
			printf("%s\n", sub.first.c_str());
			sub.second->PrintKey(depth+1);
		}

	}

private:
	map<string, Trie*, std::less<string>> subnodes;
};





int main()
{
	int n;

	cin >> n;
	Trie s;
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		vector<string> sl = split(str, '\\');
		s.insert(sl);
	}
	s.PrintKey(0);
}