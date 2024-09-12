#include <iostream>
#include <vector>
#include <map>
using namespace std;

class wordTrie
{
public:

    void Insert(const vector<string>& keys)
    {
        wordTrie* root = this;
        for (string key : keys)
        {
            if (root->inner.find(key) == root->inner.end())
            {
                root->inner[key] = new wordTrie();
            }
            root = root->inner[key];
        }


    }

    void LayerPrint(int depth)
    {
        for (auto ins : inner)
        {
            for (int i = 0; i < depth; ++i)
            {
                printf("--");
            }
            printf("%s\n", ins.first.c_str());
            ins.second->LayerPrint(depth + 1);
        }


    }

private:
    map<string, wordTrie*> inner;
};




int main()
{

    int n;
    cin >> n;
    int count = 0;
    wordTrie trie;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        vector<string> strs;
        for (int j = 0; j < k; ++j)
        {
            string temp;
            cin >> temp;
            strs.push_back(temp);
        }

        trie.Insert(strs);
    }

    trie.LayerPrint(0);

    return 0;
}