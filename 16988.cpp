#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M, max_res = -1;
int map[22][22];
bool vist[22][22];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int calc(int r, int c)
{
    int cnt = 1, die_flag = 0;
    queue<pair<int, int>> Q;
    Q.push({r, c});
    vist[r][c] = true;
    
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(map[nr][nc] == 0)
            {
                die_flag = 1;
                continue;
            }
            if(map[nr][nc] != 2 || vist[nr][nc]) continue;
            vist[nr][nc] = true;
            Q.push({nr, nc});
            cnt++;
        }
    }
    if(die_flag) return 0;
    return cnt;
}
void go(int r, int c, int cnt)
{
    // 죽는 돌의 갯수 계산
    if(cnt == 2)
    {
        memset(vist, false, sizeof(vist));
        int tmp = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(map[i][j] == 2 && vist[i][j] == false)
                {
                    tmp += calc(i, j);
                }
            }
        }
        max_res = max(max_res, tmp);
        return;
    }

    // 돌 착수
    for(int i=r; i<N; i++)
    {
        for(int j=c; j<M; j++)
        {
            if(map[i][j] == 0)
            {
                map[i][j] = 1;
                go(i, j, cnt+1);
                map[i][j] = 0;                
            }
        }
        c = 0;
    }
}
void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
        }
    }
}
void solve()
{
    go(0, 0, 0);
    cout<<max_res;
}
int main()
{
    input();
    solve();
    return 0;
}
