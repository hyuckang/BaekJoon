#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
int virus_cnt, empty_cnt;
int min_res = 987654321;
int map[55][55], vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<pair<int, int>> viruss;
bool select_virus[15];

void input();
void pr_map();
void pr_vist();
void bfs()
{
    int time = 0, empty = 0;
    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    for(int i=0; i<virus_cnt; i++)
    {
        vist[viruss[i].first][viruss[i].second] = 0;
        if(select_virus[i])
        {
            Q.push({viruss[i].first, viruss[i].second});
        }
    }

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        time = max(time, vist[cur.first][cur.second]);
        if(time > min_res)
        {   // 이미 최소 시간을 넘어감
            return;
        }
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr<0 || nr>N || nc<0 || nc>N) continue;
            if(map[nr][nc] == 1 || vist[nr][nc] >= 0) continue;
            
            Q.push({nr, nc});
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
        }
    }
}
void go(int cnt, int idx)
{
    if(idx > virus_cnt) return;
    
    if(cnt == M)
    {   // M개 선택 -> bfs 호출
        bfs();
        return;
    }

    select_virus[idx] = true;
    go(cnt+1, idx+1);
    select_virus[idx] = false;
    go(cnt, idx+1);
}
int solve()
{
    go(0, 0);
    if(min_res == 987654321) return min_res;
    else return -1;
}
int main()
{
    input();
    cout<<solve();
    return 0;
}
void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 2)
            {
                viruss.push_back({i, j});
                virus_cnt++;
            }
            else if(map[i][j] == 0)
            {
                empty_cnt++;
            }
        }
    }
}
void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void pr_vist()
{
    cout<<"=== vist ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<vist[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
