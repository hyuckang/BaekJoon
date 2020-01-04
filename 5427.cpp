#include<iostream>
#include<queue>
#include<cstring>
#define MAX 1011
using namespace std;
int T, w, h;
char maps[MAX][MAX];
int fire_vist[MAX][MAX];
int man_vist[MAX][MAX];
int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0, -1, 1};

queue<pair<int, int>> fire_Q;
queue<pair<int, int>> man_Q;

void init()
{
    memset(fire_vist, -1, sizeof(fire_vist));
    memset(man_vist, -1, sizeof(man_vist));
    while(!fire_Q.empty())
    {
        fire_Q.pop();
    }
    while(!man_Q.empty())
    {
        man_Q.pop();
    }
}

void input()
{
    cin>>w>>h;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>maps[i][j];
            if(maps[i][j] == '@')
            {
                man_Q.push({i, j});
                man_vist[i][j] = 0;
            }
            if(maps[i][j] == '*')
            {
                fire_Q.push({i,j});
                fire_vist[i][j] = 0;
            }
        }
    }
}
void solve()
{
    while(!fire_Q.empty())
    {   
        // 불 BFS
        pair<int, int> cur = fire_Q.front(); fire_Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>h || ny<0 || ny>w) continue;
            if(maps[nx][ny] == '#' || fire_vist[nx][ny] >= 0) continue;
            fire_Q.push({nx,ny});
            fire_vist[nx][ny] = fire_vist[cur.first][cur.second] + 1;
        }
    }
    
    while (!man_Q.empty())
    {   
        // 상근 BFS
        pair<int, int> cur = man_Q.front(); man_Q.pop();        
        if(cur.first == 0 || cur.second == 0 || cur.first == h-1 || cur.second == w-1)
        {
            cout<<man_vist[cur.first][cur.second] + 1<<'\n';
            return;
        }

        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>h || ny<0 || ny>w) continue;                          // 범위를 넘어서는 경우
            if(maps[nx][ny] == '#'|| man_vist[nx][ny] >= 0) continue;           // 벽이거나 이미 방문했을 경우
            if(fire_vist[nx][ny] != -1 && fire_vist[nx][ny] <= man_vist[cur.first][cur.second] + 1) continue;   // 불이 상근이보다 먼저 방문했을 경우
            man_Q.push({nx,ny});
            man_vist[nx][ny] = man_vist[cur.first][cur.second] + 1;
        }
    }
    
    cout<<"IMPOSSIBLE\n";
    return;
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    cin>>T;
    while(T--)
    {
        init();
        input();
        solve();
    }
    return 0;
}
