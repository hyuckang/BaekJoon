#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int R, C;
int map[105][105], vist[105][105];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1 ,1};
int time, cheeze_cnt;

bool is_melt(int r, int c)
{
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if(vist[nr][nc] == 1)
            return true;
    }
    return false;
}
void dfs(int r, int c, int cnt)
{
    vist[r][c] = cnt;
    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir], nc = c + dc[dir];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if(vist[nr][nc] > -1 || map[r][c] != map[nr][nc]) continue;
        dfs(nr, nc, cnt);
    }
}
void solve()
{
    if(cheeze_cnt == 0)
    {
        cout << time << "\n" << cheeze_cnt << "\n";
        return;
    }

    while(true)
    {
        time++;

        // 초기화
        memset(vist, -1 , sizeof(vist));
        
        // 공기 : 1, 치즈 : 2, 치즈 안에 구멍 : 3 이상
        dfs(0, 0, 1);
        int cnt = 3;
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                if(vist[i][j] == -1)
                {
                    if(map[i][j] == 1)
                        dfs(i, j, 2);
                    else
                        dfs(i, j, cnt++);
                }
            }
        }

        // 녹는 치즈 찾기
        vector<pair<int, int>> melt;
        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {   
                if(map[i][j] == 1 && is_melt(i, j))
                    melt.push_back(make_pair(i, j));
            }
        }

        // 치즈가 모두 녹았으면 종료
        if(cheeze_cnt == melt.size())
        {
            cout << time << "\n" << cheeze_cnt << "\n";
            return;
        }
        else
        {
            int melt_sz = melt.size();
            cheeze_cnt -= melt_sz;
            for(int i=0; i<melt_sz; i++)
                map[melt[i].first][melt[i].second] = 0;
        }
    }

}
void input()
{
    cin >> R >> C;
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1) cheeze_cnt++;
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
