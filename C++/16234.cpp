#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

int N, L, R;
int map[55][55], vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
// 인구 이동 횟수, 인구 이동 검사 플래그
int res = 0, move_flag = 0;

void bfs(int r, int c)
{
    queue<pair<int, int>> Q;
    vector<pair<int, int>> nation;
    int nation_sum = 0;

    vist[r][c] = 1;
    Q.push(make_pair(r, c));
    nation.push_back(make_pair(r, c));
    nation_sum += map[r][c];

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc <0 || nc >= N || vist[nr][nc]) continue;
            if(L > abs(map[cur.first][cur.second] - map[nr][nc]) || abs(map[cur.first][cur.second] - map[nr][nc]) > R) continue;

            Q.push(make_pair(nr, nc));
            vist[nr][nc] = 1;
            nation.push_back(make_pair(nr, nc));
            nation_sum += map[nr][nc];
        }
    }

    int nation_sz = nation.size();
    if(nation_sz > 1)
    {
        move_flag = 1;
        int nation_avg = nation_sum / nation_sz;
        for(int i=0; i<nation_sz; i++)
        {
            map[nation[i].first][nation[i].second] = nation_avg;
        }
    }    
}
void solve()
{
    while(true)
    {
        memset(vist, 0, sizeof(vist));
        move_flag = 0;

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(vist[i][j] == 0) bfs(i, j);
            }
        }

        // 인구 이동이 일어났으면 res++
        if(move_flag) res++;
        // 일어나지 않았으면 break
        else break;
    }
    cout<<res;
}
void input()
{
    cin>>N>>L>>R;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
