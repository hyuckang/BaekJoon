#include <iostream>
using namespace std;

int N;
string map[15], cur[15];
char res[15][15];
int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

char mine(int r, int c)
{
    int cnt = 0;
    for(int dir=0; dir<8; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if(map[nr][nc] == '*')
            cnt++;
    }
    return cnt + '0';
}
void call_mine()
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(map[i][j] == '*')
                res[i][j] = '*';
        }
    }
}
int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> map[i];

    for(int i=0; i<N; i++)
        cin >> cur[i];

    bool mine_flag = false;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(cur[i][j] == 'x')
            {
                if(map[i][j] == '*')
                    mine_flag = true;
                else
                    res[i][j] = mine(i, j);
            }
            else
                res[i][j] = '.';
        }
    }

    if(mine_flag) call_mine();

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << res[i][j];
        }
        cout << "\n";
    }
    
    return 0;
}
