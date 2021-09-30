#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
// vist[r][c][0] : 영역의 번호, vist[r][c][1] : 영역의 넓이
int map[55][55], vist[55][55][2];
int dr[] = {0, -1, 0, 1}, dc[] = {-1, 0, 1, 0};
int room_cnt = 0, room_max1 = -1, room_max2 = -1;

bool check_wall(int r, int c, int dir)
{
    // map[r][c] 에서 dir 방향에 벽이 있으면 return true, 벽이 없으면 return false
    // dir : 0(서), 1(북), 2(동), 3(남)
    if(map[r][c] == 0) return false;

    int cmp_val = (1 << dir);
    if(map[r][c] & cmp_val) return true;
    else return false;
}

int bfs(int r, int c, int cnt)
{
    int res = 1;

    queue<pair<int, int>> Q;
    Q.push(make_pair(r, c));
    vist[r][c][0] = cnt;
    vector<pair<int, int>> V;
    V.push_back(make_pair(r, c));

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= M || nc < 0 || nc >= N || vist[nr][nc][0] > 0) continue;
            if(check_wall(cur.first, cur.second, dir)) continue;
            
            Q.push(make_pair(nr, nc));
            vist[nr][nc][0] = cnt;
            V.push_back(make_pair(nr, nc));
            res++;
        }
    }

    int V_sz = V.size();
    for(int i=0; i<V_sz; i++) vist[V[i].first][V[i].second][1] = res;
    
    return res;
}
void solve()
{
    // 방의 갯수와 영역의 넓이 구하기
    for(int r=0; r<M; r++)
    {
        for(int c=0; c<N; c++)
        {
            if(vist[r][c][0] == 0)
            {
                room_cnt++;
                room_max1 = max(room_max1, bfs(r, c, room_cnt));
            }
        }
    }
    
    // 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
    for(int r=0; r<M; r++)
    {
        for(int c=0; c<N; c++)
        {
            for(int dir=0; dir<4; dir++)
            {
                int nr = r + dr[dir];
                int nc = c + dc[dir];
                if(nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
                if(vist[r][c][0] == vist[nr][nc][0]) continue;
                // 벽이 있으면 허물고 영역을 더한다
                if(check_wall(r, c, dir)) room_max2 = max(room_max2, vist[r][c][1] + vist[nr][nc][1]);
            }
        }
    }
    
    cout<<room_cnt<<"\n"<<room_max1<<"\n"<<room_max2<<"\n";
}
void input()
{
    cin>>N>>M;
    for(int r=0; r<M; r++)
    {
        for(int c=0; c<N; c++)
        {
            cin>>map[r][c];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
