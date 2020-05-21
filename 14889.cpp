#include<iostream>
using namespace std;

int N, min_res = 987654321;
int map[25][25], start[15];

int calc()
{
    int start_res = 0, link_res = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(start[i] && start[j]) start_res += map[i][j];
            if(!start[i] && !start[j]) link_res += map[i][j];
        }
    }
    return abs(start_res - link_res);
}
void go(int idx, int cnt)
{
    if(cnt == N/2)
    {
        min_res = min(min_res, calc());
        return;
    }
    if(idx > N) return;

    start[idx] = true;
    go(idx + 1, cnt + 1);
    start[idx] = false;
    go(idx + 1, cnt);
}
void solve()
{
    // 선택 받으면 스타트팀, 선택 받지 못하면 링크팀
    go(1, 0);
    cout<<min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
