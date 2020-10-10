#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;
string map[105];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1}, vist[105][105];

void RG_B(int r, int c)
{
    vist[r][c] = 1;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || vist[nr][nc]) continue;
        if((map[r][c] == 'R' || map[r][c] == 'G') && (map[nr][nc] == 'R' || map[nr][nc] == 'G'))
            RG_B(nr, nc);    
        else if(map[r][c] == 'B' && map[nr][nc] == 'B')
            RG_B(nr, nc);    
    }
}
void R_G_B(int r, int c)
{
    vist[r][c] = 1;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N || vist[nr][nc]) continue;
        if(map[r][c] != map[nr][nc]) continue;
        R_G_B(nr, nc);
    }
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> map[i];

    int R_G_B_res = 0, RG_B_res = 0;
    memset(vist, false, sizeof(vist));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(vist[i][j] == 0)
            {
                R_G_B_res++;
                R_G_B(i, j);
            }
        }
    }
    memset(vist, false, sizeof(vist));
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(vist[i][j] == 0)
            {
                RG_B_res++;
                RG_B(i, j);
            }
        }
    }

    cout << R_G_B_res << " " << RG_B_res;

    return 0;
}
