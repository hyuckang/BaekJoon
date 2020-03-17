#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int N, M;
int map[22][22];
int enemy_map[22][22];
int enemy_cnt;
bool vist[22][22];
int max_res = 0;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
void init();
void input();
void pr_map();
void pr_vist();

bool is_die(int r, int c)
{   // (r, c) 돌이 죽으면 true, 죽지 않으면 false
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
        if(map[nr][nc] == 0) return false;
    }
    return true;
}


int calc_bfs(int r, int c)
{
    int cnt = 1;    
    queue<pair<int, int>> Q;
    Q.push({r, c});
    vist[r][c] = true;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
            if(map[nr][nc] != 2 || vist[nr][nc]) continue;
            vist[nr][nc] = true;
            Q.push({nr, nc});
            cnt++;
            if(!is_die(nr, nc)) return 0;
        }
    }
    return cnt;
}


void go(int r, int c, int cnt)
{
    if(cnt == 2)
    {
        memset(vist, false, sizeof(vist));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(map[i][j] == 2 && vist[i][j] == false)
                {
                    int tmp = calc_bfs(i, j);
                    max_res = max(max_res, tmp);
                    // pr_vist();
                }
            }
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
    /*
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
    */


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
void pr_vist()
{
    cout<<"=== vist ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(vist[i][j]) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}
