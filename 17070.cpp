#include<iostream>
using namespace std;
int N, cnt;
int map[18][18];

bool check_go(int r, int c, int next_type)
{
    if(next_type == 0)
    {   
        if(c+1<=N && map[r][c+1] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(next_type == 1)
    {
        if(r+1<=N && map[r+1][c] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(next_type == 2)
    {
        if(r+1<=N && c+1<=N && map[r+1][c]==0 && map[r][c+1]==0 && map[r+1][c+1]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void dfs(int r, int c, int type)
{   // 0 : 가로, 1 : 세로, 2 : 대각선
    if(r==N && c==N)
    {
        cnt++;
        return;
    }
    if(type == 0)
    {   
        if(check_go(r, c, 0)) dfs(r, c+1, 0);
        if(check_go(r, c, 2)) dfs(r+1, c+1, 2);
    }
    if(type == 1)
    {
        if(check_go(r, c, 1)) dfs(r+1, c, 1);
        if(check_go(r, c, 2)) dfs(r+1, c+1, 2);
    }
    if(type ==2)
    {
        if(check_go(r, c, 0)) dfs(r, c+1, 0);
        if(check_go(r, c, 1)) dfs(r+1, c, 1);
        if(check_go(r, c, 2)) dfs(r+1, c+1, 2);
    }
}

void input()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }
}

void solve()
{
    dfs(1, 2, 0);
    cout<<cnt<<"\n";
}

int main()
{
    input();
    solve();
    return 0;
}
