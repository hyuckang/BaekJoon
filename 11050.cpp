#include<iostream>
using namespace std;

int N, K, res = 1;

int main()
{
    cin >> N >> K;
    
    for(int i=0; i<K; i++)
        res *= (N - i);
    for(int i=0; i<K; i++)
        res /= (K - i);

    cout << res;
    return 0;
}
