/*
    1. 물고기 거리 계산 -> bfs
    2. 먹을 물고기 선택
    3. 먹고 시간계산, 상어 크기 확인, 상어 위치
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, shark_r, shark_c, shark_size = 2, shark_eat = 0, res = 0;
int map[25][25], vist[25][25];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool is_eat()
{   
    // 먹을 물고기가 있다면 먹고 return true, 먹을 물고기가 없다면 return false
    
    // 먹을 물고기 찾기
    int fish_r = -1, fish_c = -1, min_res = 987654321;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] == 0 || vist[i][j] == -1) continue;    
            if(map[i][j] >= shark_size || vist[i][j] == 0) continue;
            if(min_res > vist[i][j])
            {
                min_res = vist[i][j];
                fish_r = i;
                fish_c = j;
            }
        }
    }

    // 물고기 먹기
    if(fish_r == -1 && fish_c == -1)
        return false;
    else
    {
        // 시간 게산, 상어 크기 확인
        res += vist[fish_r][fish_c];
        shark_eat++;
        if(shark_size == shark_eat)
        {
            shark_size++;
            shark_eat = 0;
        }

        // 상어 위치 옮기기
        map[shark_r][shark_c] = 0;
        map[fish_r][fish_c] = 9;
        shark_r = fish_r, shark_c = fish_c;

        return true;
    }

}
void bfs()
{
    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    vist[shark_r][shark_c] = 0;
    Q.push(make_pair(shark_r, shark_c));
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc <0 || nc >= N || vist[nr][nc] > -1) continue;
            if(map[nr][nc] > shark_size) continue;
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            Q.push(make_pair(nr, nc));
        }
    }
}
void solve()
{
    while(true)
    {
        bfs();
        if(!is_eat()) break;
    }
    cout<<res;
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
                shark_r = i, shark_c = j;
            }
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
