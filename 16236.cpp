#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M, time = 0;
int map[30][30], vist[30][30];
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
typedef struct 
{
    int r, c, size, eat_fish;
}fish;
fish shark;
void input();
void pr_map();
void pr_vist();
void bfs()
{
    // bfs, 물고기 거리 계산
    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    Q.push(make_pair(shark.r, shark.c));
    vist[shark.r][shark.c] = 0;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(vist[nr][nc] >= 0 || map[nr][nc] > shark.size) continue;
            Q.push(make_pair(nr, nc));
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
        }
    }
}
bool check_fish()
{
    // 물고기 선택
    int fish_r = -1, fish_c = -1, fish_time = 987654321;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(vist[i][j] == -1 || map[i][j] == 9) continue;
            if(map[i][j] != 0 && vist[i][j] < fish_time)
            {
                fish_time = vist[i][j];
                fish_r = i, fish_c = j;
            }
        }
    }
    if(fish_r == -1 && fish_c == -1) return false;

    cout<<"=======\n";
    cout<<"fish_r "<<fish_r<<", fish_c : "<<fish_c<<"\n";
    
    // 시간 더하기
    time += vist[fish_r][fish_c];
    if(map[fish_r][fish_c] == shark.size) shark.eat_fish++;

    // 상어 맵에 그리기
    map[shark.r][shark.c] = 0;
    map[fish_r][fish_c] = 9;
    shark.r = fish_r, shark.c = fish_c;
    

    // 상어 크기 확인
    if(shark.size == shark.eat_fish)
    {
        shark.size++;
        shark.eat_fish = 0;
    }
    return true;
}
void solve()
{
    while(true)
    {
        bfs();
        pr_vist();
        if(!check_fish()) break;
        pr_map();
        cout<<"time = "<<time<<"\n";
        cout<<"-----------------\n";
    }
    cout<<time;
}
int main()
{
    input();
    solve();
    return 0;
}
void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 9)
            {
                shark.r = i, shark.c = j, shark.size = 2, shark.eat_fish = 0;
                
            }
            else if(map[i][j] > 0)
            {
                M++;
            }
        }
    }
}
void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
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
        for(int j=0; j<N; j++)
        {
            cout<<vist[i][j]<<" ";
        }
        cout<<"\n";
    }
}
