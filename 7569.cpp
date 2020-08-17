#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
#include<cstring>
using namespace std;

int N, M, H;
vector<tuple<int, int, int>> ripe;
int ripe_cnt = 0, unripe_cnt = 0, time = -987654321;
int map[105][105][105], vist[105][105][105];
int dr[] = {-1, 1, 0, 0, 0, 0}, dc[] = {0, 0, -1, 1, 0, 0}, dh[] = {0, 0, 0, 0, -1, 1};

void solve()
{
    if(unripe_cnt == 0)
    {
        cout << 0;
        return;
    }

    memset(vist, -1, sizeof(vist));
    queue<tuple<int, int, int>> Q;
    for(int i=0; i<ripe_cnt; i++)
    {
        int r, c, h;
        tie(r, c, h) = ripe.at(i);
        vist[r][c][h] = 0;
        Q.push(make_tuple(r, c, h));
    }
    
    while(!Q.empty())
    {
        if(unripe_cnt == 0)
        {
            cout << time;
            return;
        }
        
        int r, c, h;
        tie(r, c, h) = Q.front(); Q.pop();
        for(int dir=0; dir<6; dir++)
        {
            int nr = r + dr[dir], nc = c + dc[dir], nh = h + dh[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M || nh < 0 || nh >= H) continue;
            if(map[nr][nc][nh] == -1 || vist[nr][nc][nh] >= 0) continue;
            vist[nr][nc][nh] = vist[r][c][h] + 1;
            Q.push(make_tuple(nr, nc, nh));
            time = max(time, vist[nr][nc][nh]);
            unripe_cnt--;
        }
    }

    cout << -1;
    return;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> M >> N >> H;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<N; j++)
        {
            for(int k=0; k<M; k++)
            {
                cin >> map[j][k][i];
                if(map[j][k][i] == 0)
                    unripe_cnt++;
                else if(map[j][k][i] == 1)
                {
                    ripe_cnt++;
                    ripe.push_back(make_tuple(j, k, i));
                }
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
