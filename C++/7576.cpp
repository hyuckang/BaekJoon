#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N, M;
int map[1011][1011], vist[1011][1011];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int tomato_cnt = 0;
queue<pair<int, int>> Q;
void solve()
{
    // bfs
    int vist_tomato = 0, time = 0;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        if(map[cur.first][cur.second] == 0) vist_tomato++;
        time = max(time, vist[cur.first][cur.second]);

        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];

            if(nr < 0 || nr >= N || nc <0 || nc >=M) continue;
            if(map[nr][nc] == -1 || vist[nr][nc] >= 0) continue;

            Q.push(make_pair(nr, nc));
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
        }   
    }

    if(tomato_cnt == vist_tomato) cout<<time;
    else cout<<-1;
}
void input()
{
    cin>>M>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 1)
            {
                vist[i][j] = 0;
                Q.push(make_pair(i, j));
            }
            else if(map[i][j] == 0)
            {
                tomato_cnt++;
            }
        }
    }
}
void init()
{
    memset(vist, -1, sizeof(vist));
}
int main()
{
    init();
    input();
    solve();
    return 0;
}
