#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int K, W, H;
int res = 999999999;
int map[211][211];
int vist[211][211][31];  // 0: 거리, 1~31 : 말로 이동한 횟수
int dx[] = {-1,1,0,0, -2,-2,2,2, -1,1,-1,1};
int dy[] = {0,0,-1,1, -1,1,-1,1, -2,-2,2,2};
int dx_h[] = {-2,-2,2,2, -1,1,-1,1};
int dy_h[] = {-1,1,-1,1, -2,-2,2,2};

void pr_map()
{
    cout<<"K: "<<K<<" W: "<<W<<" H:"<<H<<"\n";
    cout<<"---map---\n";
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<H; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void pr_vist(int horse)
{
    cout<<"--- "<<horse<<" map---\n";
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<H; j++)
        {
            cout<<vist[i][j][horse];
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void input_init()
{
    cin>>K;
    cin>>W>>H;
    for(int i=0; i<W; i++)
    {
        for(int j=0; j<H; j++)
        {
            cin>>map[i][j];
        }
    }
    memset(vist, -1, sizeof(vist));
}
void solve()
{
    cout<<"11111\n";
    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(0, 0, 0));
    vist[0][0][0] = 0;

    while(!Q.empty())
    {
        cout<<"2222\n";
        int cur_x, cur_y, horse;
        tie(cur_x, cur_y, horse) = Q.front(); Q.pop();
        if(cur_x == H-1 && cur_y == W-1)
        {
            cout<<"horse : "<<horse<<"\n";
            res = min(res, vist[cur_x][cur_y][horse]);
        }

        /*
        for(int dir=0; dir<4; dir++)
        {   // 그냥 가능 경우
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx<0 || nx>=H || ny<0 || ny>=W | map[nx][ny]) continue;
            if(vist[nx][ny][horse] != -1) continue;
            
            Q.push(make_tuple(nx, ny, horse));
            vist[nx][ny][horse] = vist[nx][ny][horse];
            cout<<"Q push (nx: "<<nx<<","<<ny<<")\n";
            pr_vist(horse);
            getchar();
        }

        for(int dir=0; dir<8; dir++)
        {   // 말처럼 가는 경우
            if(horse==K) break;     // 더 이상 말처럼 갈수 없음
            int nx = cur_x + dx_h[dir];
            int ny = cur_y + dy_h[dir];
            if(nx<0 || nx>=H || ny<0 || ny>=W | map[nx][ny]) continue;
            if(vist[nx][ny][horse] != -1) continue;

            Q.push(make_tuple(nx, ny, horse+1));
            vist[nx][ny][horse+1] = vist[nx][ny][horse] + 1;
            cout<<"Q push (nx: "<<nx<<","<<ny<<")\n";
            pr_vist(horse);
            getchar();
        }
        */
       
        cout<<"3333\n";
        for(int dir=0; dir<12; dir++)
        {
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            
            if(nx<0 || nx>=W || ny<0 || ny>=H | map[nx][ny]) continue;
            if(vist[nx][ny][horse] != -1) continue;

            if(dir<4)
            {   // 그냥 가는 경우
                Q.push(make_tuple(nx, ny, horse));
                vist[nx][ny][horse] = vist[cur_x][cur_y][horse] + 1;
                // cout<<"Q push (nx: "<<nx<<","<<ny<<")\n";
                pr_vist(horse);
                getchar();
            }
            else if(dir>3 && horse+1<=K)
            {   // 말처럼 가는 경우
                Q.push(make_tuple(nx, ny, horse+1));
                vist[nx][ny][horse+1] = vist[cur_x][cur_y][horse] + 1;
                // cout<<"Q push (nx: "<<nx<<","<<ny<<")\n";
                pr_vist(horse);
                getchar();
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
