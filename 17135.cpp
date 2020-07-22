#include<iostream>
#include<cstring>
using namespace std;

int N, M, D;
int map[20][20], tmp[20][20];
int enemy = 0, max_res = -987654321;

void go(int a1, int a2, int a3, int res, int enemy_cnt)
{
    // 종료 검사
    if(enemy_cnt == 0)
    {
        max_res = max(max_res, res);
        return;
    }
    for(int c=0; c<M; c++)
    {
        if(tmp[N][c] == 1)
        {
            max_res = max(max_res, res);
            return;
        }
    }

    // 적 제거
    int go_res = 0;


    // 적 이동
    for(int r=N; r>0; r--)
    {
        for(int c=0; c<M; c++)
        {
            map[r][c] = map[r - 1][c];
        }
    }
    go(a1, a2, a3, res + go_res, enemy_cnt - go_res);
}
void solve()
{
    // 궁수 3명 선택
    for(int a1=0; a1<M; a1++)
    {
        for(int a2=a1+1; a2<M; a2++)
        {
            for(int a3=a2+1; a3<M; a3++)
            {
                memcpy(tmp, map, sizeof(map));
                go(a1, a2, a3, 0, enemy);
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> D;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                enemy++;
            }
        }
    }

}
int main()
{
    input();
    solve();
    return 0;
}
