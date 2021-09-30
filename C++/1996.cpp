#include<iostream>
using namespace std;

int N, dr[] = {-1, 1, 0, 0, -1, 1, -1, 1}, dc[] = {0, 0, -1, 1, -1, -1, 1, 1};
string map[1005];
char mine_map[1005][1005];

void find_mine(int r, int c)
{
    int cnt = 0;
    for(int dir=0; dir<8; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == '.') continue;
        cnt += map[nr][nc] - '0';
    }
    if(cnt >= 10)
        mine_map[r][c] = 'M';
    else
        mine_map[r][c] = cnt + '0';
}
void solve()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] == '.')
                find_mine(i, j);
            else
                mine_map[i][j] = '*';
        }
    }

    for(int i=0; i<N; i++)
        cout << mine_map[i] << "\n";
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
