#include<iostream>
using namespace std;
int N, min_res = 987654321;
int map[25][25];
bool start[25];     // 선택한 사람은 start팀, 선택하지 않은 사람은 link 팀

int calc()
{
    int start_res = 0, link_res = 0;

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(start[i] && start[j])
            {
                start_res += map[i][j];
            }
            if(start[i] == false && start[j] == false)
            {
                link_res += map[i][j];
            }
        }
    }

    return abs(start_res - link_res);
}
void go(int cnt, int idx)
{
    if(cnt == N/2)
    {
        int res = calc();
        min_res = min(min_res, res);
        return;
    }
    if(idx > N)
    {
        return;
    }

    start[idx] = true;
    go(cnt+1, idx+1);
    start[idx] = false;
    go(cnt, idx+1);
}
void input()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }
}
void solve()
{
    go(0, 1);
    cout<<min_res;
}
int main()
{
    input();
    solve();
    return 0;
}
