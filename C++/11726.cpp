#include<iostream>
using namespace std;
int N, dp[1005];
void solve()
{
    // dp[i] : 2 * i  타일을 채우는 방법의 수
    dp[1] = 1, dp[2] = 2;
    for(int i=3; i<=N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout<<dp[N];
}
void input()
{
    cin>>N;
}
int main()
{
    input();
    solve();
    return 0;
}
