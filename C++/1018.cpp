#include <iostream>
using namespace std;

int N, M, min_res = 987654321;
string map[55];

int check_board(int r, int c)
{
    int cnt = 0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(i % 2 == 0)
            {
                if(j % 2 == 0)
                {
                    if(map[r + i][c + j] != map[r][c])
                        cnt++;
                }
                else
                {
                    if(map[r + i][c + j] == map[r][c])
                        cnt++;
                }
            }
            else
            {
                if(j % 2 == 1)
                {
                    if(map[r + i][c + j] != map[r][c])
                        cnt++;
                }
                else
                {
                    if(map[r + i][c + j] == map[r][c])
                        cnt++;
                }
            }
        }
    }
    return min(cnt, 64 - cnt);
}
int main()
{
    cin >> N >> M;
    
    for(int i=0; i<N; i++)
        cin >> map[i];

    for(int i=0; i<N-7; i++)
        for(int j=0; j<M-7; j++)
            min_res = min(min_res, check_board(i, j));

    cout << min_res;
    return 0;
}
