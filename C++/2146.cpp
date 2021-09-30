#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int map[105][105], island[105][105], vist[105][105];
int min_res = 987654321;

int bfs(int r, int c)
{
    queue<pair<int, int>> Q;
    vist[r][c] = 0;
    Q.push(make_pair(r, c));
    
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if(island[cur.first][cur.second] != 0 && island[r][c] != island[cur.first][cur.second])
            return vist[cur.first][cur.second] - 1;

        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc <0 || nc >= N) continue;
            if(island[nr][nc] == 0 && vist[nr][nc] > -1) continue;
            if(island[nr][nc] > 0 && island[nr][nc] == island[cur.first][cur.second]) continue;

            Q.push(make_pair(nr, nc));
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
        }
    }
    return 987654321;
}
bool check_edge(int r, int c)
{
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc <0 || nc >= N) continue;
        if(map[nr][nc] == 0) return true;
    }
    return false;
}
void island_check(int cnt, int r, int c)
{
    island[r][c] = cnt;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc <0 || nc >= N) continue;
        if(map[nr][nc] == 0 || island[nr][nc] > 0) continue;
        island_check(cnt, nr, nc);
    }
}
void solve()
{
    int island_cnt = 1;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            if(map[r][c] == 1 && island[r][c] == 0)
                island_check(island_cnt++, r, c);
        }
    }

    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            if(map[r][c] == 1 && check_edge(r, c))
            {
                memset(vist, -1, sizeof(vist));
                min_res = min(min_res, bfs(r, c));
            }
        }
    }     
    cout << min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);        

    cin >> N;
    for(int r=0; r<N; r++)
        for(int c=0; c<N; c++)
            cin >> map[r][c];
}
int main()
{
    input();
    solve();
    return 0;
}
