#include<iostream>
#include<vector>
using namespace std;

int arr[100005];


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        int nx;
        cin >> nx;
        num += nx;
        arr[i] = num;
    }

    for (int i = 0; i < x; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        int m = arr[v2] - arr[v1 - 1];
        printf("%d\n", m);
    }

}