#include<iostream>
using namespace std;

struct DICE
{
    int up = 0, down = 0;
    int e = 0, w = 0, s = 0, n = 0;
};
int N, M, x, y, K;
int MAP[25][25];
int dr[] = {0, 0, 0, -1, 1}, dc[] = {0, 1, -1, 0, 0};
DICE dice;

void move_dice(int dir)
{
    int tmp;
    if(dir == 1)
    {
        tmp = dice.e;
        dice.e = dice.up, dice.up = dice.w, dice.w = dice.down;
        dice.down = tmp;
    }
    else if(dir == 2)
    {
        tmp = dice.w;
        dice.w = dice.up, dice.up = dice.e, dice.e = dice.down;
        dice.down = tmp;
    }    
    else if(dir == 3)
    {
        tmp = dice.n;
        dice.n = dice.up, dice.up = dice.s, dice.s = dice.down;
        dice.down = tmp;
    }
    else              
    {
        tmp = dice.s;
        dice.s = dice.up, dice.up = dice.n, dice.n = dice.down;
        dice.down = tmp;
    }
    return;
}
void solve()
{
    while(K--)
    {
        int dir;
        cin >> dir;
        int nr = x + dr[dir], nc = y + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        
        move_dice(dir);

        if(MAP[nr][nc] == 0)
        {
            MAP[nr][nc] = dice.down;
        }
        else
        {
            dice.down = MAP[nr][nc];
            MAP[nr][nc] = 0;
        }
        
        x = nr, y = nc;
        cout << dice.up << "\n";
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> x >> y >> K;
    
    for(int r=0; r<N; r++)
        for(int c=0; c<M; c++)
            cin >> MAP[r][c];
}
int main()
{
    input();
    solve();
    return 0;
}
