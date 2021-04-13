#include <iostream>
using namespace std;

// 가장 왼쪽에 있는 좌표를 출력해야하기 때문에 탐색하는 방향이 중요!!

int board[25][25], dr[] = {-1, 0, 1, 1}, dc[] = {1, 1, 1, 0}; 
bool is_inside(int r, int c)
{
    if(1 <= r && r <= 19 && 1 <= c && c <= 19) return true;
    else return false;
}
bool check_five(int r, int c, int type, int dir)
{
    int nr = r, nc = c, cnt = 1;
    while(true)
    {
        nr = r + dr[dir] * cnt;
        nc = c + dc[dir] * cnt;
        if(!is_inside(nr, nc) || board[nr][nc] != type) break;
        cnt++;
    }

    if(cnt != 5) return false;
    else
    {
        int br = r + (dr[dir] * -1);
        int bc = c + (dc[dir] * -1);
        if(!is_inside(br, bc) || board[br][bc] != type)
            return true;
        else 
            return false;
    }
}
int main()
{
    // input
    for(int r=1; r<=19; r++)
        for(int c=1; c<=19; c++)
            cin >> board[r][c];

    // solve
    for(int r=1; r<=19; r++)
    {
        for(int c=1; c<=19; c++)
        {
            if(board[r][c] != 0)
            {
                for(int dir=0; dir<4; dir++)
                {
                    if(check_five(r, c, board[r][c], dir))
                    {
                        cout << board[r][c] << "\n";
                        cout << r << " " << c << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << 0;

    return 0;
}
