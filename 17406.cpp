#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, K;
int A[55][55], B[55][55];
int cmd_r[10], cmd_c[10], cmd_s[10];
int min_res = 987654321;

void rotate(int R, int C, int S)
{
    int tmp[55][55] = {0, };
    memcpy(tmp, B, sizeof(B));
    
    while(true)
    {
        for(int i=0; i<2*S; i++)
        {
            tmp[R - S][C - S + i + 1] = B[R - S][C - S + i];    // up
            tmp[R + S][C + S - i - 1] = B[R + S][C + S - i];    // down
            tmp[R + S - i - 1][C - S] = B[R + S - i][C -S];     // left
            tmp[R - S + i + 1][C + S] = B[R - S + i][C + S];    // right
        }
        S--;
        if(S == 0) break;
    }

    memcpy(B, tmp, sizeof(tmp));
}
void solve()
{
    int p[6] = {0, 1, 2, 3, 4, 5};
    do
    {
        memcpy(B, A, sizeof(B));

        for(int i=0; i<K; i++)
            rotate(cmd_r[p[i]], cmd_c[p[i]], cmd_s[p[i]]);

        for(int r=1; r<=N; r++)
        {
            int res = 0;
            for(int c=1; c<=M; c++)
            {
                res += B[r][c];
            }
            min_res = min(min_res, res);
        }
    } while(next_permutation(p, p + K));

    cout << min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
    for(int r=1; r<=N; r++)
        for(int c=1; c<=M; c++)
            cin >> A[r][c];
    for(int i=0; i<K; i++)
        cin >> cmd_r[i] >> cmd_c[i] >> cmd_s[i];
}
int main()
{
    input();
    solve();
    return 0;
}
