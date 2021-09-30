#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct NODE
{
    int r, c, wall = 0;
};
int N, M, K;
string map[1005];
int vist[1005][1005][11];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void solve()
{
    memset(vist, -1, sizeof(vist));
    
    NODE start;
    start.r = 0, start.c = 0, start.wall = 0;
    queue<NODE> Q;
    Q.push(start);
    for(int i=0; i<=K; i++)
        vist[0][0][i] = 1;
    
    while(!Q.empty())
    {
        NODE cur = Q.front(); Q.pop();
        NODE next;

        if(cur.r == N - 1 && cur.c == M - 1)
        {
            cout << vist[cur.r][cur.c][cur.wall];
            return;
        }    

        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            if(map[nr][nc] == '0' && vist[nr][nc][cur.wall] == -1)
            {
                next.r = nr, next.c = nc, next.wall = cur.wall;
                Q.push(next);
                vist[nr][nc][next.wall] = vist[cur.r][cur.c][cur.wall] + 1;
            }
            else if(map[nr][nc] == '1' && cur.wall < K && vist[nr][nc][cur.wall + 1] == -1)
            {
                next.r = nr, next.c = nc, next.wall = cur.wall + 1;
                Q.push(next);
                vist[nr][nc][next.wall] = vist[cur.r][cur.c][cur.wall] + 1;
            }
        }

    }
    cout << -1;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0; i<N; i++)
        cin >> map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
