#include<iostream>
using namespace std;

int TC, N;
long long DP[100][100];

long long go_dp(int W_cnt, int H_cnt)
{
    if(H_cnt == 0)
    {
        if(DP[W_cnt - 1][H_cnt + 1] == 0)
            DP[W_cnt - 1][H_cnt + 1] = go_dp(W_cnt - 1, H_cnt + 1);
            return DP[W_cnt - 1][H_cnt + 1];
    }
    else if(W_cnt == 0)
    {
        return 1;
    }
    else
    {
        if(DP[W_cnt - 1][H_cnt + 1] == 0)
            DP[W_cnt - 1][H_cnt + 1] = go_dp(W_cnt - 1, H_cnt + 1);
        if(DP[W_cnt][H_cnt - 1] == 0)
            DP[W_cnt][H_cnt - 1] = go_dp(W_cnt, H_cnt - 1);
        return DP[W_cnt - 1][H_cnt + 1] + DP[W_cnt][H_cnt - 1];
    }
}
void solve()
{
    // DP[W][H]
    // -> 한조각의 약의 개수 W, 반조각의 약의 개수 H로 만들수 있는 서로 다른 문자열의 개수
    // DP[W][H] = DP[W - 1][H + 1] + DP[W][H - 1]
    // DP[0][i] = 1 ('H', 'HH', ...)
    // DP[i][0] = DP[i - 1][1];

    cout << go_dp(N, 0) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true)
    {
        cin >> N;
        if(N == 0) break;
        solve();
    }
    
    return 0;
}
