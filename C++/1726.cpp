#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int map[105][105], vist[105][105][5];
int dr[] = {0, 0, 0, 1, -1}, dc[] = {0, 1, -1, 0, 0};
struct Node
{
    int r, c, dir;
};
Node START, END;
int turn_dir(int cur_dir, int next_dir)
{   
    // cur_dir에서 next_dir로 바꾸기 위한 명령의 수
    if(cur_dir == 1 && next_dir == 2) return 2;
    else if(cur_dir == 2 && next_dir == 1) return 2;
    else if(cur_dir == 3 && next_dir == 4) return 2;
    else if(cur_dir == 4 && next_dir == 3) return 2;
    
    return 1;
}
void solve()
{
    memset(vist, -1, sizeof(vist));

    queue<Node> Q;
    vist[START.r][START.c][START.dir] = 0;
    Q.push(START);

    while(!Q.empty())
    {
        Node next, cur = Q.front(); Q.pop();
        if(END.r == cur.r && END.c == cur.c && END.dir == cur.dir) break;

        // Turn dir
        // GO K는 모든 가중치가 1이나, Turn dir은 방향에 따라 가중치가 2가 될 수 도 있기 때문에
        // 방향을 돌 때, 최소 명령이 달라질 수 있음
        next.r = cur.r, next.c = cur.c;
        for(int k=1; k<=4; k++)
        {
            int turn_res = vist[cur.r][cur.c][cur.dir] + turn_dir(cur.dir, k);
            if(vist[cur.r][cur.c][k] == -1 || vist[cur.r][cur.c][k] > turn_res)
            {
                vist[cur.r][cur.c][k] = turn_res;
                next.dir = k;
                Q.push(next);                
            }            
        }

        // GO k
        int wall_flag = false;
        for(int k=1; k<=3; k++)
        {
            if(wall_flag) break;
            int nr = cur.r + dr[cur.dir] * k;
            int nc = cur.c + dc[cur.dir] * k;
            if(nr <= 0 || nr > N || nc <= 0 || nc > M || vist[nr][nc][cur.dir] >= 0) continue;
            if(map[nr][nc])
            {
                wall_flag = true;
                continue;
            }
            
            next.r = nr, next.c = nc, next.dir = cur.dir;
            vist[next.r][next.c][next.dir] = vist[cur.r][cur.c][cur.dir] + 1;
            Q.push(next);
        }
    }
    cout<<vist[END.r][END.c][END.dir];
}
void input()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin>>map[i][j];
        }
    }
    cin>>START.r>>START.c>>START.dir;
    cin>>END.r>>END.c>>END.dir;
}
int main()
{
    input();
    solve();
    return 0;
}
