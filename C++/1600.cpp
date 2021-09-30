#include<iostream>
#include<queue>
#include<tuple>
#include<cstring>
using namespace std;
int K, W, H;
int map[222][222];
int vist[222][222][31];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int hr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int hc[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void init()
{
    memset(vist, -1, sizeof(vist));
}
void input()
{
    cin>>K>>W>>H;
    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            cin>>map[i][j];
        }
    }
}
int solve()
{   
    queue<tuple<int, int, int>> Q;
    for(int i=0; i<K; i++)
    {
        vist[0][0][i] = 0;
    }
    Q.push(make_tuple(0, 0, 0));
    while(!Q.empty())
    {
        int r, c, jump;
        tie(r, c, jump) = Q.front(); Q.pop();
        if(r == H-1 && c == W-1)
        {
            return vist[r][c][jump];
        }
        for(int dir=0; dir<4; dir++)
        {   // 그냥 이동
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if(nr<0 || nr>=H || nc<0 || nc>=W)
            {
                continue;
            }
            if(map[nr][nc] || vist[nr][nc][jump] >= 0)
            {
                continue;
            }
            Q.push(make_tuple(nr, nc, jump));
            vist[nr][nc][jump] = vist[r][c][jump] + 1;
        }
        if(jump < K)
        {
            // 말처럼 이동
            for(int dir=0; dir<8; dir++)
            {   
                int nr = r + hr[dir];
                int nc = c + hc[dir];
                if(nr<0 || nr>=H || nc<0 || nc>=W)
                {
                    continue;
                }
                if(map[nr][nc] || vist[nr][nc][jump+1] >= 0)
                {
                    continue;
                }
                Q.push(make_tuple(nr, nc, jump+1));
                vist[nr][nc][jump+1] = vist[r][c][jump] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    init();
    input();
    cout<<solve();
    return 0;
}
