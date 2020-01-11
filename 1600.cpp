#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int K, W, H;
int res = 999999999;
int map[201][201];
int vist[201][201][30];  // 0: 거리, 1~31 : 말로 이동한 횟수
int dx[] = {-1,1,0,0, -2,-2,2,2, -1,1,-1,1};
int dy[] = {0,0,-1,1, -1,1,-1,1, -2,-2,2,2};

void input_init()
{
    cin>>K;
    cin>>W>>H;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            cin>>map[i][j];
        }
    }
    memset(vist, -1, sizeof(vist));
}
void solve()
{ 
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(0, 0, 0));
    vist[0][0][0] = 0;

    while(!Q.empty())
    {
        int cur_x, cur_y, horse;
        tie(cur_x, cur_y, horse) = Q.front(); Q.pop();
        if(cur_x == H-1 && cur_y == W-1)
        {
            res = min(res, vist[cur_x][cur_y][horse]);
        }
        
        for(int dir=0; dir<12; dir++)
        {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            
            if(nx<0 || nx>=H || ny<0 || ny>=W | map[nx][ny]) continue;
            if(vist[nx][ny][horse] > -1) continue;
            
            if(dir<4)
            {   // 그냥 가는 경우
                Q.push(make_tuple(nx, ny, horse));
                vist[nx][ny][horse] = vist[cur_x][cur_y][horse] + 1;
            }
            else if(dir>3 && horse+1<=K)
            {   // 말처럼 가는 경우
                Q.push(make_tuple(nx, ny, horse+1));
                vist[nx][ny][horse+1] = vist[cur_x][cur_y][horse] + 1;
            }
        }
        
    }

    if(res == 999999999)
    {
        cout<<-1;
    }
    else
    {
        cout<<res;
    }

}
int main()
{
    input_init();
    solve();
    return 0;
}
