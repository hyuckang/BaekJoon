#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define MAX 1011

int N, island;
int map[MAX][MAX][2];   //  0 : map, 1 : 섬의 번호
int dist_map[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int min_bridge = 0xFFFFFF;

bool check_edge(int i, int j)
{
    // 4면 중 바다가 있으면 true를 반환
    for(int dir=0; dir<4; dir++)
    {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if(nx<=0 || nx>N || ny<=0 || ny>N) continue;
        if(map[nx][ny][0] == 0) return true; 
    }
    return false;
}

void input()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j][0];
        }
    }
}

void solve()
{
    // 연결요소 찾기
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<N; j++)
        {
            if(!map[i][j][0] || map[i][j][1] != 0) continue;
            island++;       // 위 조건을 빠져나오면 새로운 섬을 찾음

            queue<pair<int, int>> Q;
            Q.push({i, j});
            map[i][j][1] = island;
            while(!Q.empty())
            {
                pair<int, int> cur = Q.front(); Q.pop();
                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<=0 || nx>N || ny<=0 || ny>N) continue;
                    if(!map[nx][ny][0] || map[nx][ny][1] != 0) continue;
                    Q.push({nx,ny});
                    map[nx][ny][1] = island;
                }
            }
        }
    }

    // 다리 만들기
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(!map[i][j][0] || !check_edge(i,j)) continue; // 바다이거나, 4면 중 바다가 없으면 continue 
            
            memset(dist_map, -1, sizeof(dist_map));
            queue<pair<int, int>> bridge_Q;
            bridge_Q.push({i, j});
            dist_map[i][j] = 0;

            while(!bridge_Q.empty())
            {
                pair<int, int> cur = bridge_Q.front(); bridge_Q.pop();
                
                if(dist_map[cur.first][cur.second] > min_bridge) break;

                for(int dir=0; dir<4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<=0 || nx>N || ny<=0 || ny>N) continue;    // 범위를 벗어나는 경우
                    if(dist_map[nx][ny] >= 0) continue;             // 이미 방문한 경우
                    if(map[nx][ny][0])
                    {
                        if(map[i][j][1] == map[nx][ny][1]) continue;    // 같은 섬인 경우
                        else    // 새로운 섬을 찾은 경우
                        {
                            if(dist_map[cur.first][cur.second] < min_bridge)
                            {
                                min_bridge = dist_map[cur.first][cur.second];
                                break;
                            }
                        }
                    }
                    bridge_Q.push({nx, ny});
                    dist_map[nx][ny] = dist_map[cur.first][cur.second] + 1;
                    
                }
            }
        }
    }
    // 정답 출력
    cout<<min_bridge<<"\n";
}

int main()
{
    input();
    solve();
    return 0;
}