#include<iostream>
#include<vector>
using namespace std;
int map[505][505], cnt[505][505];
pair<int, int> dest[505][505];
int R, C;
int dr[] = {0, -1, 1, 0, 0, -1, -1, 1, 1};
int dc[] = {0, 0, 0, -1, 1, -1, 1, -1, 1};

void memo_route(int dest_r, int dest_c, vector<pair<int, int>> &route)
{
    int route_sz = route.size();
    cnt[dest_r][dest_c]++;

    for(int i=0; i<route_sz; i++)
    {
        dest[route[i].first][route[i].second].first = dest_r;
        dest[route[i].first][route[i].second].second = dest_c;
    }
}
void go(int r, int c, vector<pair<int, int>> &route)
{
    route.push_back(make_pair(r, c));

    
    int min_r = -1, min_c = -1, min_val = 999999;
    // 방문하지 않았으면
    if(dest[r][c].first == 0 && dest[r][c].second == 0)
    {
        for(int dir=0; dir<9; dir++)
        {
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr <= 0 || nr > R || nc <= 0 || nc > C) continue;
            if(map[nr][nc] < min_val)
                min_r = nr, min_c = nc, min_val = map[nr][nc];
        }
        // 이동 불가능
        if(min_r == r && min_c == c)
        {
            memo_route(min_r, min_c, route);
            return;
        }
        // 이동 가능
        else
            go(min_r, min_c, route);
    }
    // 방문했으면
    else
    {
        route.push_back(make_pair(dest[r][c].first, dest[r][c].second));
        memo_route(dest[r][c].first, dest[r][c].second, route);
        return;
    }
}
void solve()
{
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            vector<pair<int, int>> route;
            go(i, j, route);
        }
    }
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cout<<cnt[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    for(int i=1; i<=R; i++)
        for(int j=1; j<=C; j++)
            cin >> map[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
