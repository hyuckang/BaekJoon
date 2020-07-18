#define first r
#define second c
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
string map[105];
int vist[105][105];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void solve()
{
    memset(vist, -1, sizeof(vist));
    deque<pair<int, int>> DQ;
    DQ.push_front(make_pair(0, 0));
    vist[0][0] = 0;

    while(!DQ.empty())
    {
        pair<int, int> cur = DQ.front(); DQ.pop_front();
        if(cur.r == M - 1 && cur.c == N -1)
        {
            cout << vist[M - 1][N - 1];
            return;
        }
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.r + dr[dir], nc = cur.c + dc[dir];
            if(nr < 0 || nr >= M || nc < 0 || nc >= N || vist[nr][nc] >= 0) continue;
            if(map[nr][nc] == '0')
            {
                vist[nr][nc] = vist[cur.r][cur.c];
                DQ.push_front(make_pair(nr, nc));
            }
            else // map[nr][nc] == '1'
            {
                vist[nr][nc] = vist[cur.r][cur.c] + 1;
                DQ.push_back(make_pair(nr, nc));
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++)
        cin >> map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
