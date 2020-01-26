#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int T,w,h;
char map[1001][1001];
int fire_vist[1001][1001];
int man_vist[1001][1001];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> fire_Q;
queue<pair<int, int>> man_Q;

void pr_map()
{
    cout<<"== map ==\n";
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void pr_vist()
{   
    cout<<"==fire_vist==\n";
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout<<fire_vist[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"==man_vist==\n";
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout<<man_vist[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
void init()
{
    while (!fire_Q.empty())
    {
        fire_Q.pop();
    }
    while(!man_Q.empty())
    {
        man_Q.pop();
    }
    memset(fire_vist, -1, sizeof(fire_vist));
    memset(man_vist, -1, sizeof(man_vist));
}

void input()
{
    cin>>w>>h;
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == '*')
            {
                fire_Q.push({i,j});
                fire_vist[i][j] = 0;
            }
            else if(map[i][j] == '@')
            {
                man_Q.push({i, j});
                man_vist[i][j] = 0;
            }
        }
    }
}

void solve()
{
    // fire bfs
    while(!fire_Q.empty())
    {
        pair<int, int> cur = fire_Q.front(); fire_Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(map[nx][ny] == '#' || fire_vist[nx][ny] >=0) continue;

            fire_Q.push({nx, ny});
            fire_vist[nx][ny] = fire_vist[cur.first][cur.second] + 1;
        }
    }

    // man bfs
    while(!man_Q.empty())
    {
        pair<int, int> cur = man_Q.front(); man_Q.pop();
        if(cur.first == 0 || cur.first == h-1 || cur.second == 0 || cur.second == w-1)
        {
            cout<<man_vist[cur.first][cur.second]+1<<"\n";
            return;
        }
        
        for(int dir=0; dir<4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
            if(map[nx][ny] == '#' || man_vist[nx][ny] >=0) continue;
            // compare fire, man
            if(fire_vist[nx][ny] != -1 && fire_vist[nx][ny] <= man_vist[cur.first][cur.second] + 1) continue;

            man_Q.push({nx, ny});
            man_vist[nx][ny] = man_vist[cur.first][cur.second] + 1;
        }

    }
    
    cout<<"IMPOSSIBLE\n";
    
}
int main()
{
    cin>>T;
    while(T--)
    {
        init();
        input();
        solve();
        pr_vist();
    }
    
    return 0;
}
