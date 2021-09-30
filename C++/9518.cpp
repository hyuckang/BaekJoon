#include<iostream>
using namespace std;

int R, S;
int dr[] = {-1, 1, 0, 0, -1, 1, -1, 1}, dc[] = {0, 0, -1, 1, -1, -1, 1, 1};
char map[55][55];
int max_handshake = -987654321;
pair<int, int> max_position;

int hand_shake(int r, int c)
{
    int res = 0;
    for(int dir=0; dir<8; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= R || nc < 0 || nc >= S) continue;
        if(map[nr][nc] == 'o') res++;
    }
    return res;
}
void solve()
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<S; j++)
        {
            if(map[i][j] == '.')
            {
                int handshake_res = hand_shake(i, j);
                if(max_handshake < handshake_res)
                {
                    max_handshake = handshake_res;
                    max_position.first = i, max_position.second = j;
                }
            }
        }
    }

    map[max_position.first][max_position.second] = 'o';
    int res = 0;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<S; j++)
        {
            if(map[i][j] == 'o')
            {
                res += hand_shake(i, j);
            }
        }
    }
    cout << res / 2;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> S;
    for(int i=0; i<R; i++)
        for(int j=0; j<S; j++)
            cin >> map[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
