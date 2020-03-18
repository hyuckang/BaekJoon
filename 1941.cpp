#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char map[30][30];
int vist[30][30];
int bfs_vist[30][30];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
int res;

int bfs(int r, int c)
{
    int cnt = 1;
    queue<pair<int, int>> Q;
    bfs_vist[r][c] = 1;
    Q.push({r, c});
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr<0 || nr>=5 || nc<0 || nc>=5) continue;
            if(bfs_vist[nr][nc] == 1 || vist[nr][nc] == 0) continue;
            Q.push({nr, nc});
            bfs_vist[nr][nc] = 1;
            cnt++;
        }
    }
    return cnt;
}
void go(int r, int c, int cnt, int S_cnt, int Y_cnt)
{
    // 7명을 선택하기 전에 Y가 4명 이상이면 불가능함
    if(Y_cnt >= 4) return;
    if(cnt == 7)
    {   // 7명 모두 선택했으면 bfs로 7명이 모여있는지 확인
        memset(bfs_vist, 0, sizeof(bfs_vist));
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<5; j++)
            {
                // bfs는 한번만 호출 되어야 함
                if(vist[i][j] == 1)
                {   
                    if(bfs(i, j) == 7)
                    {   
                        res++;
                    }
                    return;
                }
            }
        }
    }

    // 25명 중 7명을 중복되지 않게 선택
    for(int i=r; i<5; i++)
    {
        for(int j=c; j<5; j++)
        {
            if(vist[i][j] == 1) continue;
            vist[i][j] = 1;
            if(map[i][j] == 'S') go(i, j, cnt+1, S_cnt+1, Y_cnt);
            else go(i, j, cnt+1, S_cnt, Y_cnt+1);
            vist[i][j] = 0;
        }
        c = 0;
    }
}
void solve()
{
    go(0, 0, 0, 0, 0);
    cout<<res;
}
void input()
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
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
