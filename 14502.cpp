#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
int N, M, safe_area;
int map[9][9], vist[9][9];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
vector<pair<int, int>> viruss;

int calc_safe_area()
{
    memset(vist, -1, sizeof(vist));

    queue<pair<int, int>> viruss_Q;
    size_t virus_cnt = viruss.size();
    for(size_t i=0; i<virus_cnt; i++)
    {
        viruss_Q.push({viruss[i].first, viruss[i].second});
        vist[viruss[i].first][viruss[i].second] = 0;
    }

    while(!viruss_Q.empty())
    {
        pair<int, int> cur = viruss_Q.front(); viruss_Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr<=0 || nr>N || nc<=0 || nc>M) continue;
            if(map[nr][nc] || vist[nr][nc] > 0) continue;

            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            viruss_Q.push({nr, nc});
            
        }
    }

    int res = 0;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            if(map[r][c] == 0 && vist[r][c] == -1)
            {
                res++;
            }
        }
    }

    return res;
}

void make_wall(int r, int c, int cnt)
{
    if(4 <= cnt)
    {
        return;
    }

    if(cnt == 3)
    {
        int calc_safe_area_res = calc_safe_area();
        if(calc_safe_area_res > safe_area)
        {
            safe_area = calc_safe_area_res;
        }
        return;
    }

    for(int i=r; i<=N; i++)
    {
        for(int j=c; j<=M; j++)
        {
            
            if(map[i][j] == 0)
            {
                map[i][j] = 1;
                make_wall(i, j, cnt+1);
                map[i][j] = 0;
            }
        }
        c = 1;
    }
}

void input()
{
    cin>>N>>M;
    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=M; c++)
        {
            cin>>map[r][c];
            if(map[r][c] == 2)
            {
                viruss.push_back({r, c});
            }
        }
    }
}

void solve()
{
    make_wall(1, 1, 0);
    cout<<safe_area<<"\n";
}

int main()
{
    input();
    solve();
    return 0;
}
