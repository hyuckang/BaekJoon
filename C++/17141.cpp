#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
int map[55][55], vist[55][55];
int spread = 0, min_res = 987654321;
vector<pair<int, int>> vir;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int bfs(vector<int> &selc)
{
    memset(vist, -1, sizeof(vist));
    int spread_cnt = 0;

    queue<pair<int, int>> Q;
    for(int i=0; i<M; i++)
    {
        Q.push(make_pair(vir[selc[i]].first, vir[selc[i]].second));
        vist[vir[selc[i]].first][vir[selc[i]].second] = 0;
        spread_cnt++;
    }

    if(spread == spread_cnt)
        return 0;

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(map[nr][nc] == 1 || vist[nr][nc] >= 0) continue;

            Q.push(make_pair(nr, nc));
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            spread_cnt++;
            if(spread_cnt == spread)
            {
                return vist[nr][nc];
            }
        }
    }
    return 987654321;
    
}
void go(int idx, int cnt, vector<int> &selc)
{
    if(idx > vir.size()) return;

    if(cnt == M)
    {
        int res = bfs(selc);
        min_res = min(min_res, res);
        return;
    }

    selc.push_back(idx);
    go(idx + 1, cnt + 1, selc);
    selc.pop_back();
    go(idx + 1, cnt, selc);
}

void solve()
{
    vector<int> select;
    go(0, 0, select);
    
    if(min_res == 987654321)
        cout << -1;
    else
        cout << min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 0)
                spread++;
            else if(map[i][j] == 2)
            {
                vir.push_back(make_pair(i, j));
                spread++;
            }
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
