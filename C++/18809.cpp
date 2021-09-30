/*
    1. 조합을 구하자
    2. bfs
*/
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int N, M, R, G;
int map[55][55];
int vist[55][55][2]; // 0:초록색(G), 1:빨간색(R)
bool flower_map[55][55];
vector<pair<int, int>> yellow;
int yellow_cnt = 0, max_res = -1;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs(vector<pair<int, char>> &A)
{
    int flower_cnt = 0;
    memset(vist, -1, sizeof(vist));
    memset(flower_map, false, sizeof(flower_map));
    queue<tuple<int, int, char>> Q;
    for(int i=0; i< R + G; i++)
    {   
        // 방문표시하고 큐에 넣는다
        int idx;
        if(A[i].second == 'G') idx = 0;
        else idx = 1;

        vist[yellow[A[i].first].first][yellow[A[i].first].second][idx] = 0;
        Q.push(make_tuple(yellow[A[i].first].first, yellow[A[i].first].second, A[i].second));
    }
    while(!Q.empty())
    {
        int r, c;
        char color;
        tie(r, c, color) = Q.front(); Q.pop();
        if(flower_map[r][c]) continue;

        for(int dir=0; dir<4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 0) continue;

            // G 일때
            if(color == 'G')
            {
                // 이미 방문했거나, 꽃이 핀 곳이라면 넘어간다
                if(vist[nr][nc][0] >= 0 || flower_map[nr][nc]) continue;

                // 꽃이 피는 경우
                if(vist[r][c][0] + 1 == vist[nr][nc][1])
                {
                    flower_cnt++;
                    flower_map[nr][nc] = true;
                    continue;
                }
                
                // 꽃이 피지 않는 경우                
                if(vist[nr][nc][1] == -1)
                {
                    Q.push(make_tuple(nr, nc, color));
                    vist[nr][nc][0] = vist[r][c][0] + 1;
                }

            }
            // R 일때
            else
            {
                if(vist[nr][nc][1] >= 0 || flower_map[nr][nc]) continue;

                if(vist[r][c][1] + 1 == vist[nr][nc][0])
                {
                    flower_cnt++;
                    flower_map[nr][nc] = true;
                    continue;
                }
                
                if(vist[nr][nc][0] == -1)
                {
                    Q.push(make_tuple(nr, nc, color));
                    vist[nr][nc][1] = vist[r][c][1] + 1;
                }
            }
        }
    }
    return flower_cnt;
}
void go(int idx, int R_cnt, int G_cnt, vector<pair<int, char>> &A)
{
    if(idx > yellow_cnt || R_cnt > R || G_cnt > G) return;
    if(R_cnt == R && G_cnt == G)
    {
        max_res = max(max_res, bfs(A));
        return;
    }

    // idx 번째에 R 선택
    if(R_cnt < R)
    {
        A.push_back(make_pair(idx, 'R'));
        go(idx + 1, R_cnt + 1, G_cnt, A);
        A.pop_back();
    }
    
    // idx 번째에 G 선택
    if(G_cnt < G)
    {
        A.push_back(make_pair(idx, 'G'));
        go(idx + 1, R_cnt, G_cnt + 1, A);
        A.pop_back();
    }
    
    // idx 번째 선택 X
    go(idx + 1, R_cnt, G_cnt, A);
}
void solve()
{
    vector<pair<int, char>> R_G; // idx 번째 벡터에 R, G를 의미
    go(0, 0, 0, R_G);
    cout<<max_res;
}
void input()
{
    cin>>N>>M>>G>>R;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 2)
            {
                yellow.push_back({i, j});
                yellow_cnt++;
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
