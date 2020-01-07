#include<iostream>
#include<queue>
#include<cstring>
#define x first
#define y second
using namespace std;

int N,M;
int map[111][111];
int vist_map[111][111][2];          // 0 : 거리(명령), 1 : 방향
int dx[] = {0, 0, 0,   0, 0, 0,  1, 2, 3,  -1, -2, -3};
int dy[] = {1, 2, 3,  -1,-2,-3,  0, 0, 0,   0,  0,  0};
int dir_val[5];
pair<pair<int, int>, int> START;    // 행, 열, 방향
pair<pair<int, int>, int> END;

void make_dir_val(int i, int j)
{
    if(vist_map[i][j][1] == 1)
    {
        dir_val[1]=1, dir_val[2]=3, dir_val[3]=2, dir_val[4]=2;
    }
    else if(vist_map[i][j][1] == 2)
    {
        dir_val[1]=3, dir_val[2]=1, dir_val[3]=2, dir_val[4]=2;
    }
    else if(vist_map[i][j][1] == 3)
    {
        dir_val[1]=2, dir_val[2]=2, dir_val[3]=1, dir_val[4]=3;
    }
    else if(vist_map[i][j][1] == 4)
    {
        dir_val[1]=2, dir_val[2]=2, dir_val[3]=3, dir_val[4]=1;
    }
}

void input()
{
    cin>>M>>N;
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }
    cin>>START.x.x>>START.x.y>>START.y;
    cin>>END.x.x>>END.x.y>>END.y;
}

void solve()
{
    memset(vist_map, -1, sizeof(vist_map));
    queue<pair<int, int>> Q;
    Q.push({START.x.x, START.x.y});
    vist_map[START.x.x][START.x.y][0] = 0;
    vist_map[START.x.x][START.x.y][1] = START.y;

    while(!Q.empty())
    {   
        pair<int, int> cur = Q.front(); Q.pop();
        make_dir_val(cur.x, cur.y);

        if(cur.x == END.x.x && cur.y == END.x.y)
        {
            cout<<vist_map[cur.x][cur.y][0] + dir_val[END.y]- 1;
            break;
        }

        for(int dir=0; dir<12; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx<1 || nx>M || ny<1 || ny>N) continue;
            if(map[nx][ny] || vist_map[nx][ny][0] >-1) continue;
            
            if(dir%3 == 1)
            {
                int block_check_x = cur.x + dx[dir-1];
                int block_check_y = cur.y + dy[dir-1];
                if(map[block_check_x][block_check_y]) continue;
            }
            else if(dir%3==2)
            {
                int block_check_x = cur.x + dx[dir-1];
                int block_check_y = cur.y + dy[dir-1];
                int block_check_xx = cur.x + dx[dir-2];
                int block_check_yy = cur.y + dy[dir-2];
                if(map[block_check_xx][block_check_yy] || map[block_check_x][block_check_y]) continue;
            }
            
            Q.push({nx, ny});
            vist_map[nx][ny][0] = vist_map[cur.x][cur.y][0] + dir_val[dir/3+1];
            vist_map[nx][ny][1] = dir/3 + 1;
        }
    }
}
int main()
{
    input();
    solve();
}
