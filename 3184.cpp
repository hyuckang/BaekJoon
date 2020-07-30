#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

string map[255];
int vist[255][255];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int R, C, sheep, wolf;

void dfs(int r, int c, int cnt)
{
    vist[r][c] = cnt;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if(map[nr][nc] == '#' || vist[nr][nc] >= 0) continue;
        dfs(nr, nc, cnt);
    }
}
void solve()
{
    memset(vist, -1, sizeof(vist));

    // 영역 구하기
    int cnt = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(map[i][j] != '#' && vist[i][j] == -1)
                dfs(i, j, cnt++);
        }
    }
    
    // 영역별 양과 늑대 확인
    vector<pair<int, int>> sheep_wolf;
    for(int i=0; i<cnt; i++)
    {
        int o_res = 0, v_res = 0;
        for(int r=0; r<R; r++)
        {
            for(int c=0; c<C; c++)
            {
                if(vist[r][c] == i)
                {
                    if(map[r][c] == 'o')
                        o_res++;
                    else if(map[r][c] == 'v')
                        v_res++;
                }
            }
        }
        sheep_wolf.push_back(make_pair(o_res, v_res));
    }

    // 영역별로 양과 늑대 계산
    for(int i=0; i<cnt; i++)
    {
        if(sheep_wolf[i].second == 0)
            sheep += sheep_wolf[i].first;
        else if(sheep_wolf[i].first > sheep_wolf[i].second)
            sheep += sheep_wolf[i].first;
        else
            wolf += sheep_wolf[i].second;
    }

    cout << sheep << " " << wolf;    
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;
    for(int i=0; i<R; i++)
        cin >> map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
