#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int N, M;
string map[1001];
int vist[1001][1001][2];    // 0:벽을 부수고 오지 않은 경로, 1:벽을 부수고 온 경로
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void init()
{
    memset(vist, -1, sizeof(vist));
}

void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        cin>>map[i];
    }
}

void solve()
{   
    // BFS
    queue<tuple<int, int, int>> Q;
    vist[0][0][0] = 1;
    vist[0][0][1] = 1;
    Q.push(make_tuple(0, 0, 0));
    while(!Q.empty())
    {
        int r, c, wall;
        tie(r, c, wall) = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr<0 || nr>=N || nc<0 || nc>=M)
            {
                continue;
            }
            if(vist[nr][nc][wall] >= 0)
            {
                continue;
            }
            if(map[nr][nc] == '0')
            {   // 다음이 빈공간이라면 Q에 그냥 넣는다
                Q.push(make_tuple(nr, nc, wall));
                vist[nr][nc][wall] = vist[r][c][wall] + 1;
            }

            if(map[nr][nc] == '1' && wall == 0)
            {   // 다음이 벽이고, 벽을 부수지 않았다면
                // 벽을 부수고 Q에 집어넣는다.
                Q.push(make_tuple(nr, nc, 1));
                vist[nr][nc][1] = vist[r][c][0] + 1;
            }
        }
    }
    if(vist[N-1][M-1][0] == -1)
    {   // 벽을 부수지 않은 경로로는 N-1, M-1에 도착하지 못했다면
        cout<<vist[N-1][M-1][1]<<"\n";
    }
    else if(vist[N-1][M-1][1] == -1)
    {   
        cout<<vist[N-1][M-1][0]<<"\n";
    }
    else
    {
        cout<<min(vist[N-1][M-1][0], vist[N-1][M-1][1])<<"\n";
    }
    
}
int main()
{
    init();
    input();
    solve();
    return 0;
}
