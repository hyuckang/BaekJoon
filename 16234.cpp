#include<iostream>
#include<cstring>
using namespace std;
int N, L, R;
int map[55][55], vist[55][55];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
void input();
void pr_vist();

void move_people()
{
    
}
bool is_open()
{
    // 국경이 열린다면 true, 열리지 않는다면 false
    for(int r=0; r<N-1; r++)
    {
        for(int c=0; c<N-1; c++)
        {
            int diff = abs(map[r][c] - map[r][c+1]);
            if(L <= diff && diff <= R) return true;
            diff = abs(map[r][c] - map[r+1][c]);
            if(L <= diff && diff <= R) return true;
        }
    }
    return false;
}
void dfs(int r, int c, int cnt)
{
    vist[r][c] = cnt;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr<0 || nr>=N || nc<0 || nc>=N) continue;
        if(vist[nr][nc] != -1) continue;
        int diff = abs(map[r][c] - map[nr][nc]);
        if(L <= diff && diff <= R) dfs(nr, nc, cnt); 
    }
}
void solve()
{
    int res = 0;
    while(true)
    {   
        // 국경이 열리는지 검사
        if(!is_open()) break;

        // 연합 구하기
        memset(vist, -1, sizeof(vist));
        int nation_num = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(vist[i][j] == -1)
                {
                    dfs(i, j, nation_num);
                    nation_num++;
                }
            }
        }
        pr_vist();

        // 인구 이동
        break;
        
    }
    cout<<res;
}
int main()
{
    input();
    solve();
    return 0;
}
void input()
{
    cin>>N>>L>>R;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
        }
    }
}
void pr_vist()
{
    cout<<"=== map ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<vist[i][j]<<" ";
        }
        cout<<"\n";
    }
}
