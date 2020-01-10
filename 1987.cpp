#include<iostream>
using namespace std;

int R, C;
int max_res = 1;
char map[25][25];
bool check_alpha[26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int cur_x, int cur_y, int cnt)
{
    max_res = max(max_res, cnt);
    check_alpha[map[cur_x][cur_y] - 'A'] = true;

    for(int dir=0; dir<4; dir++)
    {
        int nx = cur_x + dx[dir];
        int ny = cur_y + dy[dir];
        if(nx<=0 || nx>R || ny<=0 || ny>C) continue;
        if(check_alpha[map[nx][ny] - 'A']) continue;
        dfs(nx, ny, cnt+1);
    }
    check_alpha[map[cur_x][cur_y] - 'A'] = false;
}

void input()
{
    cin>>R>>C;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cin>>map[i][j];
        }
    }    
}
void solve()
{
    dfs(1,1,1);
    cout<<max_res;
    return;
}
int main()
{
    input();
    solve();
    return 0;
}
