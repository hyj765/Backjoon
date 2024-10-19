#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;


class Trie
{
public:
	Trie()
	{
		for (int i = 0; i < 26; ++i)
		{
			subnode[i] = nullptr;
		}
	}
	
	void insert(const char* key)
	{
		if (*key == '\0')
		{
			end = true;
			return;
		}

		int index = *key - 'a';
		if (subnode[index] == nullptr)
		{
			subnode[index] = new Trie();
		}
		subnode[index]->insert(key + 1);
	}

	bool find(const char* key)
	{
		Trie* root = this;
		int len = strlen(key);
		for (int i = 0; key[i] != '\0'; ++i)
		{
			int index = key[i] - 'a';
			if (root->subnode[index] == nullptr)
			{
				return false;
			}
			
			root = root->subnode[index];
		}
		
		return true;
	}

private:
	Trie* subnode[26];
	bool end = false;
};



int main()
{
	int n, m;
	Trie root;
	cin >> n >> m;
	string str;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		root.insert(str.c_str());
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> str;
		if (root.find(str.c_str()) == true)
		{
			cnt++;
		}
	}
		
	printf("%d", cnt);
}