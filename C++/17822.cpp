#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N, M, T;
int map[55][55];
bool vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void dfs(int r, int c, vector<pair<int, int>> &remove)
{
    vist[r][c] = true;
    remove.push_back(make_pair(r, c));

    // 원판의 1번째 숫자와 M번째 숫자는 연결되있음
    if(c == 1) 
    {
        if(!vist[r][M] && (map[r][c] == map[r][M])) dfs(r, M, remove);
    }
    else if(c == M)
    {
        if(!vist[r][1] && (map[r][c] == map[r][1])) dfs(r, 1, remove);
    }

    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr <= 0 || nr > N || nc <= 0 || nc > M || vist[nr][nc]) continue;
        if(map[r][c] == map[nr][nc]) dfs(nr, nc, remove);
    }
}

void rotate(int circle_num, int dir, int k)
{
    int tmp[55];
    for(int i=0; i<=M; i++) tmp[i] = map[circle_num][i]; 

    // 시계 방향으로 k 번 돌리는 것은 반시계 방향으로 M-k 번 돌리는 것과 같다
    if(dir == 1) k = M - k;
    
    for(int i=0; i<M; i++)
    {
        int next = ((i + k) % M) + 1;
        map[circle_num][next] = tmp[i + 1];
    }
}

void solve()
{
    
    while(T--)
    {
        int x, d, k;
        cin>>x>>d>>k;

        // 회전
        for(int i=1; i * x <=N; i++) rotate(i * x, d, k);
        
        // 인접한 숫자 찾기
        bool remove_flag = false;
        memset(vist, false, sizeof(vist));
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                if(vist[i][j] || map[i][j] == -1) continue;

                vector<pair<int, int>> remove;
                dfs(i, j, remove);
                if(remove.size() >= 2)
                {
                    remove_flag = true;
                    int remove_sz = remove.size();
                    for(int i=0; i<remove_sz; i++)
                    {
                        map[remove[i].first][remove[i].second] = -1;
                    }
                }
            }
        }


        // 숫자가 지워지 않았으면, 평균 계산 후 맵에 그리기
        if(remove_flag) continue;
        
        // 평균 구하기
        vector<pair<int, int>> not_remove;
        double map_sum = 0;
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=M; j++)
            {
                if(map[i][j] == -1) continue;
                not_remove.push_back(make_pair(i, j));
                map_sum += map[i][j];
            }
        }

        // 평균으로 비교하여 원판의 숫자에 +1 또는 -1 하기
        double not_remove_sz = not_remove.size();
        double map_avg = map_sum / not_remove_sz;
        for(int i=0; i<not_remove_sz; i++)
        {
            if(map[not_remove[i].first][not_remove[i].second] > map_avg) map[not_remove[i].first][not_remove[i].second]--;
            else if(map[not_remove[i].first][not_remove[i].second] < map_avg) map[not_remove[i].first][not_remove[i].second]++;
        }
    }
    
    // 원판의 점수 계산
    int map_sum = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            if(map[i][j] == -1) continue;
            map_sum += map[i][j];
        }
    }
    cout<<map_sum;
}
void input()
{
    cin>>N>>M>>T;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            cin>>map[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
