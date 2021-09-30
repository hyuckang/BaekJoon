#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
int map[10][10], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
int min_res = 987654321;

vector<pair<int, int>> CCTV;
vector<vector<int>> CCTV_dirs[6] = 
{
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {0, 3}},
    {{0, 1, 3}, {0, 1, 2}, {1, 2, 3}, {0, 2, 3}},
    {{0, 1, 2, 3}}
};
int check()
{
    int res = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(map[i][j] == 0) res++;

    return res;
}
void down(int r, int c, int dir)
{
    int nr = r, nc = c;
    while(true)
    {
        nr += dr[dir], nc += dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 6)
            return;
        else if(0 < map[nr][nc])
            continue;
        else
            map[nr][nc]++;
    }
}
void up(int r, int c, int dir)
{
    int nr = r, nc = c;
    while(true)
    {
        nr += dr[dir], nc += dc[dir];
        if(nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 6)
            return;
        else if(0 < map[nr][nc])
            continue;
        else
            map[nr][nc]--;
    }
}
void go(int idx)
{
    if(idx >= K)
    {
        min_res = min(min_res, check());
        return;
    }

    int CCTV_r = CCTV[idx].first, CCTV_c = CCTV[idx].second;
    int CCTV_type = map[CCTV[idx].first][CCTV[idx].second];

    if(CCTV_type == 1)
    {
        // 4가지
        for(int cnt=0; cnt<4; cnt++)
        {
            // 1방향
            for(int i=0; i<1; i++)
                up(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
            
            go(idx + 1);
            
            for(int i=0; i<1; i++)
                down(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
        }
    }
    else if(CCTV_type == 2)
    {
        // 2가지
        for(int cnt=0; cnt<2; cnt++)
        {
            // 2방향
            for(int i=0; i<2; i++)
                up(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
            
            go(idx + 1);

            for(int i=0; i<2; i++)
                down(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
        }
    }
    else if(CCTV_type == 3)
    {
        // 4가지
        for(int cnt=0; cnt<4; cnt++)
        {
            // 2방향
            for(int i=0; i<2; i++)
                up(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);

            go(idx + 1);

            for(int i=0; i<2; i++)
                down(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
        }
    }
    else if(CCTV_type == 4)
    {
        // 4가지
        for(int cnt=0; cnt<4; cnt++)
        {
            // 3방향
            for(int i=0; i<3; i++)
                up(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);

            go(idx + 1);
            
            for(int i=0; i<3; i++)
                down(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
        }
    }
    else
    {
        // 1가지
        for(int cnt=0; cnt<1; cnt++)
        {
            // 4방향
            for(int i=0; i<4; i++)
                up(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
            
            go(idx + 1);

            for(int i=0; i<4; i++)
                down(CCTV_r, CCTV_c, CCTV_dirs[CCTV_type][cnt][i]);
        }
    }
}
void solve()
{
    go(0);
    cout << min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin >> map[i][j];
            if(0 < map[i][j] && map[i][j] < 6)
                CCTV.push_back(make_pair(i, j));
        }
    }
    K = CCTV.size();
}
int main()
{
    input();
    solve();
    return 0;
}
