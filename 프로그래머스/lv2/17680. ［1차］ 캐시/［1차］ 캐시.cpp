#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int isExistInCache(const vector<string>& cache,const string& s) {
    for (int i = 0; i < cache.size(); ++i) {
        if (cache[i] == s) {
            return i;
        }
       
    }
    return -1;
}
//  1    2   3   4  
// 제주 판교 서울 뉴욕 판교 뉴욕 강남 인천
void CacheUpdate(vector<string>& cache, string s, const int& addr, const int& cacheSize) {
    if (cacheSize <= cache.size()) {
        if (addr != -1) {
            cache.push_back(s);
            cache.erase(cache.begin() + addr);
        }
        else {
            cache.push_back(s);
            cache.erase(cache.begin());
        }
    }
    else {
        if (addr != -1) {
            cache.push_back(s);
            cache.erase(cache.begin() + addr);
        }
        else {
            cache.push_back(s);
        }
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    vector<string>cache;
    cache.reserve(30);
    for (int i = 0; i < cities.size(); ++i) {
        transform(cities[i].begin(),cities[i].end(),cities[i].begin(), ::tolower);
        int addr= isExistInCache(cache,cities[i]);
        if (addr == -1) {
            CacheUpdate(cache, cities[i], addr, cacheSize);
            answer += 5;
        }
        else {
            CacheUpdate(cache, cities[i], addr, cacheSize);
            answer += 1;
        }
    }

    return answer;
}