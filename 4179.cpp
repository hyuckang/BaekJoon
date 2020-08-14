#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int R, C;
int J[1005][1005], F[1005][1005];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
string map[1005];
queue<pair<int, int>> JQ, FQ;

void solve()
{
    memset(J, -1, sizeof(J));
    memset(F, -1, sizeof(F));
    
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(map[i][j] == 'J')
            {
                JQ.push(make_pair(i, j));
                J[i][j] = 0;
            }
            else if(map[i][j] == 'F')
            {
                FQ.push(make_pair(i, j));
                F[i][j] = 0;
            }
        }
    }
    
    while(!FQ.empty())
    {
        pair<int, int> cur = FQ.front(); FQ.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
            if(F[nr][nc] >= 0) continue;
            FQ.push(make_pair(nr, nc));
            F[nr][nc] = F[cur.first][cur.second] + 1;
        }
    }
    while(!JQ.empty())
    {
        pair<int, int> cur = JQ.front(); JQ.pop();
        if(cur.first == 0 || cur.first == R - 1 || cur.second == 0 || cur.second == C - 1)
        {
            cout << J[cur.first][cur.second] + 1;
            return;
        }
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
            if(J[nr][nc] >= 0 || (F[nr][nc] != -1 && J[cur.first][cur.second] + 1 >= F[nr][nc])) continue;
            JQ.push(make_pair(nr, nc));
            J[nr][nc] = J[cur.first][cur.second] + 1;
        }
    }
    cout << "IMPOSSIBLE";
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C;
    for(int i=0; i<R; i++)
        cin >> map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
