#include <string>
#include <vector>

using namespace std;
int countOnes(int num) {
    int count = 0;
    while (num != 0) {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}
int solution(int n) {
    int answer = 0;
    int cur = n;
    int nCount = countOnes(n);
    while(1){
        cur++;
        if(nCount == countOnes(cur)){
            break;
        }
    }
    answer = cur;
    return answer;
}

/*

    #include<bitset>
    
    int solution(int n) {

	int num = bitset<20>(n).count();
	while (bitset<20>(++n).count() != num);

	return n;
}




*/
