#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int map[305][305], vist[305][305];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void dfs(int r, int c)
{
    vist[r][c] = 1;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if(map[nr][nc] == 0 || vist[nr][nc] == 1) continue;
        dfs(nr, nc);
    }
}
int seperate()
{
    memset(vist, 0, sizeof(vist));

    int cnt = 0;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            if(map[r][c] > 0 && vist[r][c] == 0)
            {
                cnt++;
                dfs(r, c);
            }
        }
    }
    return cnt;
}
bool melt()
{
    queue<pair<pair<int, int>, int>> Q;
    bool melt_flag = false;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            if(map[r][c] == 0) continue;
            else
            {
                melt_flag = true;
                int cnt = 0;
                for(int dir=0; dir<4; dir++)
                {
                    int nr = r + dr[dir], nc = c + dc[dir];
                    if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                    if(map[nr][nc] == 0) cnt++;
                }
                Q.push(make_pair(make_pair(r, c), cnt));         
            }
        }
    }

    while(!Q.empty())
    {
        pair<pair<int, int>, int> cur = Q.front(); Q.pop();
        map[cur.first.first][cur.first.second] -= cur.second;
        if(map[cur.first.first][cur.first.second] < 0)
            map[cur.first.first][cur.first.second] = 0;
    }
    return melt_flag;
}
void solve()
{
    int time = 0;
    while(true)
    {
        time++;

        if(!melt())
        {
            time = 0;
            break;
        }
        if(seperate() >= 2)
            break;
    }
    cout << time;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            cin >> map[r][c];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
