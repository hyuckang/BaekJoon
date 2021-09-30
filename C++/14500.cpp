#include<iostream>
using namespace std;

int N, M, A[505][505], vist[505][505];
int max_res = -987654321;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void puple(int r, int c)
{
    // ㅜ
    if(r + 1 < N && 0 <= c - 1 && c + 1 < M)
        max_res = max(max_res, A[r][c] + A[r + 1][c] + A[r][c - 1] + A[r][c + 1]);
    // ㅗ    
    if(0 <= r -1 && 0 <= c - 1 && c + 1 < M)
        max_res = max(max_res, A[r][c] + A[r - 1][c] + A[r][c - 1] + A[r][c + 1]);
    // ㅏ    
    if(0 <= r -1 && r + 1 < N  && c + 1 < M)
        max_res = max(max_res, A[r][c] + A[r - 1][c] + A[r + 1][c] + A[r][c + 1]);
    // ㅓ
    if(0 <= r -1 && r + 1 < N && 0 <= c - 1)
        max_res = max(max_res, A[r][c] + A[r - 1][c] + A[r + 1][c] + A[r][c - 1]);
}
void dfs(int r, int c, int cnt, int sum)
{
    if(cnt == 4)
    {
        max_res = max(max_res, sum);
        return;
    }

    vist[r][c] = 1;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || vist[nr][nc]) continue;
        vist[nr][nc] = 1;
        dfs(nr, nc, cnt + 1, sum + A[nr][nc]);
        vist[nr][nc] = 0;
    }
    vist[r][c] = 0;
}
void solve()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            dfs(i, j, 1, A[i][j]);
            puple(i, j);
        }
    }

    cout << max_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> A[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
