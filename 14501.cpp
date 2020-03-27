#include<iostream>
using namespace std;
int N, max_res = -1;
int map[20][20];
void go(int idx, int pay_sum)
{
    if(idx > N + 1) return;
    if(idx == N + 1)
    {
        max_res = max(max_res, pay_sum);
        return;
    }
    // idx 번째 상담 한다
    go(idx + map[0][idx], pay_sum + map[1][idx]);

    // idx 번째 상담 하지 않는다
    go(idx + 1, pay_sum);
}
void solve()
{
    go(1, 0);
    cout<<max_res;
}
void input()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>map[0][i]>>map[1][i];
    }
}
int main()
{
    input();
    solve();
    return 0;
}
