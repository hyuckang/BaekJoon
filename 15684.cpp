#include <iostream>
using namespace std;

int N, M, H;
int map[35][15];
int min_res = 987654321;

bool can_make(int r, int c)
{
    if(map[r][c] == 0 && map[r][c + 1] == 0)
        return true;
    else
        return false;
}
bool check()
{
    for(int c=1; c<=N; c++)
    {
        int start = c;
        for(int r=1; r<=H; r++)
        {
            start += map[r][start];
        }
        if(c != start)
            return false;
    }
    return true;
}
void go(int r, int c, int cnt)
{
    // 사다리의 개수가 4가 넘었는지 먼저 확인해야함
    if(cnt > 3)
        return;
    if(check())
    {
        min_res = min(min_res, cnt);
        return;
    }

    for(int i=r; i<=H; i++)
    {
        // 마지막 세로줄에는 사다리를 놓을 수 없기에, j는 N-1까지
        for(int j=c; j<N; j++)
        {            
            if(map[i][j] == 1 || map[i][j + 1] == -1)
                continue;
            if(can_make(i, j))
            {
                map[i][j] = 1;
                map[i][j + 1] = -1;
                go(i, j, cnt + 1);
                map[i][j] = 0;
                map[i][j + 1] = 0;
            }
        }
        c = 1;
    }
}
void solve()
{
    go(1, 1, 0);
    
    if(min_res == 987654321)
        cout << -1;
    else
        cout << min_res;
}
void input()
{
    cin >> N >> M >> H;
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
        map[a][b + 1] = -1;
    }    
}
int main()
{
    input();
    solve();
    return 0;
}
