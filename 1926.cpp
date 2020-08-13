#include<iostream>
#include<queue>
using namespace std;

int N, M, cnt = 0, size = -987654321;
int map[505][505], vist[505][505];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int bfs(int r, int c)
{
    vist[r][c] = 1;
    queue<pair<int, int>> Q;
    Q.push(make_pair(r, c));
    
    int res = 1;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(map[nr][nc] == 0 || vist[nr][nc] == 1) continue;
            
            res++;
            vist[nr][nc] = 1;
            Q.push(make_pair(nr, nc));
        }
    }

    return res;
}
void solve()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(map[i][j] == 1 && vist[i][j] == 0)
            {
                cnt++;
                int res = bfs(i, j);
                size = max(size, res);
            }
        }
    }

    cout << cnt << "\n";
    if(size == -987654321)
        cout << 0 << "\n";
    else
        cout << size << "\n";
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
