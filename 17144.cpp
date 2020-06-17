#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct NODE
{
    int r, c, val;
};
int R, C, T, map[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<int> cleaner;

int calc_dust()
{
    int res = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            res += map[i][j];
        }
    }
    res += 2;
    return res;
}
void wind()
{
    pair<int, int> air;
    air.first = cleaner.at(0), air.second = cleaner.at(1);
    
    // 1 열
    for(int i=air.first-2; i>-1; i--)
        map[i+1][0] = map[i][0];

    for(int i=air.second+2; i<R;i++)
        map[i-1][0] = map[i][0];

    // 1 행, R-1 행
    for(int i=1; i<C; i++)
    {
        map[0][i-1] = map[0][i];
        map[R-1][i-1] = map[R-1][i];
    }
    
    // C-1 열
    for(int i=1; i<=air.first; i++)
        map[i-1][C-1] = map[i][C-1];
    for(int i=R-2; i>=air.second ;i--)
        map[i+1][C-1] = map[i][C-1];

    // 청정기 행
    for(int i=C-2; i>0; i--)
    {
        map[air.first][i+1] = map[air.first][i];
        map[air.second][i+1] = map[air.second][i];
    }
    map[air.first][1] = 0, map[air.second][1] = 0;
}
void spread_dust(int r, int c, int dust_val)
{
    int div_dust = dust_val / 5;
    int cnt = 0;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == -1) continue;
        cnt++;
        map[nr][nc] += div_dust;
    }
    map[r][c] -= (cnt * div_dust);
}
void dust()
{
    queue<NODE> Q;
    NODE tmp;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(map[i][j] >= 5)
            {
                tmp.r = i, tmp.c = j, tmp.val = map[i][j];
                Q.push(tmp);
            }
        }
    }
    while(!Q.empty())
    {
        NODE tmp = Q.front(); Q.pop();
        spread_dust(tmp.r, tmp.c, tmp.val);
    }
}
void solve()
{
    while(T--)
    {
        dust();
        wind();
    }
    cout << calc_dust();
}
void input()
{
    cin >> R >> C >> T;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == -1) cleaner.push_back(i);
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
