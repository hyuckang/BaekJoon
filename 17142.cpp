#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
int map[55][55], vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int min_time = 987654321, empty_cnt = 0, virus_size;
vector<pair<int, int>> virus;

int bfs(vector<int> &select_virus)
{
    memset(vist, -1, sizeof(vist));
    int time = 0, empty_vist = 0;
    queue<pair<int, int>> Q;
    
    for(int i=0; i<M; i++)
    {   
        vist[virus[select_virus[i]].first][virus[select_virus[i]].second] = 0;
        Q.push(make_pair(virus[select_virus[i]].first, virus[select_virus[i]].second));
    }

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if(map[cur.first][cur.second] == 0)
        {
            empty_vist++;
            time = max(time, vist[cur.first][cur.second]);
            if(time > min_time) return -1;
        }

        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(map[nr][nc] == 1 || vist[nr][nc] >= 0) continue;

            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            Q.push(make_pair(nr, nc));
        }
    }

    if(empty_cnt == empty_vist) return time;
    else return -1;
}
void go(int idx, int cnt, vector<int> &select_virus)
{
    if(idx > virus_size) return;
    if(cnt == M)
    {
        int bfs_res = bfs(select_virus);
        if(bfs_res == -1) return;
        else
        {
            min_time = min(min_time, bfs_res);
            return;
        }
    }

    select_virus.push_back(idx);
    go(idx + 1, cnt + 1, select_virus);
    select_virus.pop_back();
    go(idx + 1, cnt, select_virus);
}
void solve()
{
    virus_size = virus.size();
    vector<int> select_virus;
    go(0, 0, select_virus);

    if(min_time == 987654321) cout<<-1;
    else cout<<min_time;
}
void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 0) empty_cnt++;
            else if(map[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
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
