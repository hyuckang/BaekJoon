#include<iostream>
using namespace std;

int K;
// 버튼을 K번 눌렀을 때의 A와 B의 개수
pair<int, int> D[50];
int main()
{
    cin >> K;
    D[0].first = 1, D[0].second = 0;
    D[1].first = 0, D[1].second = 1;
    for(int i=2; i<=K; i++)
    {
        D[i].first = D[i-2].first + D[i-1].first;
        D[i].second = D[i-2].second + D[i-1].second;
    }
    cout << D[K].first << " " << D[K].second;
    return 0;
}
