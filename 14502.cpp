#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
int N, M, max_safe_area = -987654321;
int map[10][10], vist[10][10];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<pair<int, int>> virus;

int calc_safe_area()
{
    memset(vist, -1, sizeof(vist));

    queue<pair<int, int>> Q;
    size_t virus_cnt = virus.size();
    for(size_t i=0; i<virus_cnt; i++)
    {
        Q.push(make_pair(virus[i].first, virus[i].second));
        vist[virus[i].first][virus[i].second] = 0;
    }

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
            if(map[nr][nc] || vist[nr][nc] >= 0) continue;

            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            Q.push({nr, nc});
        }
    }

    int safe_area = 0;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            if(map[r][c] == 0 && vist[r][c] == -1) safe_area++;
        }
    }
    return safe_area;
}

void make_wall(int r, int c, int cnt)
{
    if(cnt >= 4) return;

    if(cnt == 3)
    {
        max_safe_area = max(max_safe_area, calc_safe_area());
        return;
    }

    for(int i=r; i<=N; i++)
    {
        for(int j=c; j<=M; j++)
        {
            if(map[i][j] == 0)
            {
                map[i][j] = 1;
                make_wall(i, j, cnt + 1);
                map[i][j] = 0;
            }
        }
        c = 1;
    }
}
void solve()
{
    make_wall(1, 1, 0);
    cout<<max_safe_area<<"\n";
}
void input()
{
    cin>>N>>M;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            cin>>map[r][c];
            if(map[r][c] == 2) virus.push_back({r, c});
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
