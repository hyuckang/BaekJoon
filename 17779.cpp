#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A[25][25], map[25][25];
int min_res = 987654321;

int calc()
{
    int res[6] = {0, };
    for(int r=1; r<=N; r++)
        for(int c=1; c<=N; c++)
            res[map[r][c]] += A[r][c];

    sort(res + 1, res + 6);
    return res[5] - res[1];
}
void area(int x, int y, int d1, int d2)
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            map[i][j] = 0;
    
    for(int line=0; line<=d1; line++)
    {
        map[x + line][y - line] = 5;            // 1
        map[x + d2 + line][y + d2 - line] = 5;  // 4
    }
    for(int line=0; line<=d2; line++)
    {
        map[x + line][y + line] = 5;            // 2
        map[x + d1 + line][y - d1 + line] = 5;  // 3
    }

    for(int r=x+1; r<x+d1+d2; r++)
    {
        vector<int> pos;
        for(int c=1; c<=N; c++)
        {
            if(map[r][c] == 5)
                pos.push_back(c);
        }
        for(int c=pos[0]; c<=pos[1]; c++)
            map[r][c] = 5;
    }

    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=N; c++)
        {
            if(map[r][c] == 5) continue;
            if(r < x + d1 && c <= y)
                map[r][c] = 1;
            else if(r <= x + d2 && y < c)
                map[r][c] = 2;
            else if(x + d1 <= r && c < y - d1 + d2)
                map[r][c] = 3;
            else if(x + d2 < r && y - d1 + d2 <= c)
                map[r][c] = 4;
        }
    }
}
void solve()
{
    for(int x=1; x<=N; x++)
    {
        for(int y=1; y<=N; y++)
        {
            for(int d1=1; (x+d1<=N)&&(1<=y-d1); d1++)
            {
                for(int d2=1; (x+d1+d2<=N)&&(y+d2<=N); d2++)
                {
                    area(x, y, d1, d2);
                    min_res = min(min_res, calc());
                }
            }
        }
    }
    cout << min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> A[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
