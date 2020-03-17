#include<iostream>
#include<queue>
using namespace std;
int N, M;
int map[22][22];
int enemy_map[22][22];
int enemy_cnt;
int max_res = 0;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
void init();
void input();
void pr_map();
void pr_enemy();

bool check_die(int r, int c)
{   // (r, c) 돌이 빈칸과 맞닿아있지 않으면, 죽으면 false
    // 빈칸과 맞닿아있으면, 살면 true
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
        if(map[nr][nc] == 0) return true;
    }
    return false;
}
int kill(int num)
{
    // num 번째 상대 집합이 죽는 지 확인
    int cnt = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(enemy_map[i][j] != num) continue;
            if(check_die(i, j)) return 0;
            cnt++;
        }
    }
    return cnt;
}
void dfs(int r, int c, int cnt)
{
    enemy_map[r][c] = cnt;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
        if(map[nr][nc] != 2 || enemy_map[nr][nc] > 0) continue;
        dfs(nr, nc, cnt);
    }
}

void go(int r, int c, int cnt)
{
    if(cnt == 2)
    {
        pr_map();
        // 죽이는 돌 계산
        for(int i=1; i<=enemy_cnt; i++)
        {
            int tmp = kill(i);
            max_res = max(max_res, tmp);
            cout<<"tmp = "<<tmp<<"\n";
        }
        return;
    }
    for(int i=r; i<N; i++)
    {
        for(int j=c; j<M; j++)
        {
            if(map[i][j] == 0)
            {
                map[i][j] = 1;
                go(i, j, cnt+1);
                map[i][j] = 0;                
            }
        }
        c = 0;
    }
}
void solve()
{
    // 상대 돌의 집합 계산
    enemy_cnt = 1;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(map[i][j] == 2 && enemy_map[i][j] == 0)
            {
                dfs(i, j, enemy_cnt);
                enemy_cnt++;
            }
        }
    }
    
    enemy_cnt--;
    cout<<"enemy cnt : "<<enemy_cnt<<"\n";
    pr_enemy();

    // 돌 2개 착수
    go(0, 0, 0);

    cout<<"max_res : "<<max_res;

}
int main()
{
    input();
    solve();
    return 0;
}
void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
        }
    }
}
void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void pr_enemy()
{
    cout<<"=== enemy ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cout<<enemy_map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
