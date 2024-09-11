#include <iostream>
#include <vector>
using namespace std;


class trie
{
    public:
    trie(): Finish(false)
    {
        for(int i=0; i<10; ++i)
        {
            node[i] = NULL;
        }
    }
    
    void insert(const char* str)
    {
        if(*str == '\0')
        {
            Finish = true;
            return;
        }
        
        int cur = *str - '0';
        if(node[cur] == NULL) node[cur] = new trie();
        node[cur]->insert(str+1);
        
    }
    
    bool find(const char* str)
    {
        if(*str == '\0')
        {
            return false;
        }
        
        if(Finish == true)
        {
            return true;
        }
        
        int cur = *str - '0';
        if(node[cur] == NULL) return false;
        return node[cur]->find(str + 1);
    }
    
    private:
    bool Finish;
    trie* node[10];
};



int main()
{
    
    int tc,n;
    cin >> tc;
   
    while(tc--)
    {
        trie phone;
        vector<string> strlist;
        bool good = false;
        cin >> n;
        for(int j=0; j<n; ++j)
        {
            string s;
            cin >> s;
            strlist.push_back(s);
            phone.insert(s.c_str());       
        }
        
        for(int i=0; i<n; ++i)
        {
            if(phone.find(strlist[i].c_str()))
            {
                good = true;
                break;
            }
        }
        
        if(good) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    
    

    return 0;
}