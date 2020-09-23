#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M, D, max_res = -987654321;
int map[20][20], t_map[20][20];
int dr[] = {0, -1, 0}, dc[] = {-1, 0, 1};

pair<int, int> attack(int x)
{
    int vist[20][20];
    memset(vist, -1, sizeof(vist));

    queue<pair<int, int>> Q;
    Q.push(make_pair(N, x));
    vist[N][x] = 0;

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        
        if(t_map[cur.first][cur.second] == 1 && vist[cur.first][cur.second] <= D)
            return make_pair(cur.first, cur.second);

        for(int dir=0; dir<3; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || vist[nr][nc] >= 0) continue;
            Q.push(make_pair(nr, nc));
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
        }
    }
    return make_pair(-1, -1);
}
int game(int a, int b, int c)
{
    int res = 0, archor[3] = {a, b, c};
    
    for(int turn=0; turn<N; turn++)
    {
        // 공격
        vector<pair<int, int>> V;
        for(int i=0; i<3; i++)
        {   
            pair<int, int> enemy = attack(archor[i]);
            if(enemy.first != -1 && enemy.second != -1)
                V.push_back(enemy);
        }            
        for(size_t i=0; i<V.size(); i++)
        {
            if(t_map[V[i].first][V[i].second] == 1)
                res++;
            t_map[V[i].first][V[i].second] = 0;
        }

        // 이동
        for(int i=0; i<M; i++)
            for(int j=N; j>0; j--)
                t_map[j][i] = t_map[j - 1][i];
                
        for(int i=0; i<M; i++)
        {
            t_map[0][i] = 0;
            t_map[N][i] = 0;
        }
    }
    return res;
}
void solve()
{
    for(int a1=0; a1<M; a1++)
    {
        for(int a2=a1+1; a2<M; a2++)
        {
            for(int a3=a2+1; a3<M; a3++)
            {
                memcpy(t_map, map, sizeof(map));
                max_res = max(max_res, game(a1, a2, a3));
            }
        }
    }
    cout << max_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> D;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> map[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
