#include<iostream>
using namespace std;

int N, dp[1000005];
void solve()
{
    // dp[i] : i를 1로 만드는데 필요한 최소 연산수
    dp[1] = 0;
    for(int i=2; i<=N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if(i%3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
        if(i%2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
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
