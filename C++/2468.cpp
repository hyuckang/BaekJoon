#include<iostream>
#include<cstring>
using namespace std;

int N, map[105][105], vist[105][105];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int max_safe_area = -987654321, max_rain = -987654321, rain = 0;

void dfs(int r, int c, int cnt)
{
    vist[r][c] = cnt;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(vist[nr][nc] > -1 || map[nr][nc] <= rain) continue;
        dfs(nr, nc, cnt);
    }
}
void solve()
{
    
    while(rain <= max_rain)
    {
        memset(vist, -1, sizeof(vist));
        int cnt = 0;

        // 안전영역 구하기
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(map[i][j] > rain && vist[i][j] == -1)
                {
                    dfs(i, j, cnt++);
                }
            }
        }

        max_safe_area = max(max_safe_area, cnt);
        rain++;
    }
    cout << max_safe_area;
}
void input()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
            max_rain = max(max_rain, map[i][j]);
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
