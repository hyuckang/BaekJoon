#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct NODE
{
    int r, c, dir;
    bool end = false;
    int D[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
};

int N, M, K, time = 0;
int dr[] = {0, -1, 1, 0, 0}, dc[] = {0, 0, 0, -1, 1};
vector<int> shark_map[25][25];
pair<int, int> smell[25][25];
NODE shark[405];

bool is_end()
{
    if(time > 1000)
    {
        time = -1;
        return true;
    }

    int flag = true;
    for(int i=2; i<=M; i++)
    {
        if(shark[i].end == false)
        {
            flag = false;
            break;
        }
    }
    return flag;
}
void check_shark()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int shark_sz = shark_map[i][j].size();
            if(shark_sz > 1)
            {
                sort(shark_map[i][j].begin(), shark_map[i][j].end());
                for(int x=0; x<shark_sz-1; x++)
                {
                    shark[shark_map[i][j].back()].end = true;
                    shark_map[i][j].pop_back();
                }
                smell[i][j].first = shark_map[i][j].at(0);
            }

        }
    }
}
void reduce_smell()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if(0 < smell[i][j].second)
            {
                smell[i][j].second--;
                if(smell[i][j].second == 0)
                    smell[i][j].first = 0;
            }
        }
    }

    for(int i=1; i<=M; i++)
    {
        if(shark[i].end) continue;
        smell[shark[i].r][shark[i].c].first = i;
        smell[shark[i].r][shark[i].c].second = K;
    }
}
void move_shark()
{
    for(int x=1; x<=M; x++)
    {
        if(shark[x].end) continue;

        // 냄새 없는 칸
        int next_r = 987654321, next_c = 987654321, next_dir;
        for(int i=1; i<=4; i++)
        {
            int nr = shark[x].r + dr[ shark[x].D[shark[x].dir][i] ];
            int nc = shark[x].c + dc[ shark[x].D[shark[x].dir][i] ];
            if(nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
            if(smell[nr][nc].second > 0) continue;

            next_r = nr, next_c = nc, next_dir = shark[x].D[shark[x].dir][i];
            break;
        }
        
        // 냄새 없는 칸이 없다면
        if(next_r == 987654321 && next_c == 987654321)
        {
            for(int i=1; i<=4; i++)
            {
                int nr = shark[x].r + dr[ shark[x].D[shark[x].dir][i] ];
                int nc = shark[x].c + dc[ shark[x].D[shark[x].dir][i] ];
                if(nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
                if(smell[nr][nc].first == x )
                {
                    next_r = nr, next_c = nc, next_dir = shark[x].D[shark[x].dir][i];
                    break;
                }
            }
        }

        // 상어 옮기기
        shark_map[shark[x].r][shark[x].c].pop_back();
        shark_map[next_r][next_c].push_back(x);
        // 상어 위치 바꾸기
        shark[x].r = next_r, shark[x].c = next_c, shark[x].dir = next_dir;
    }
}
void solve()
{
    while(true)
    {
        time++;
        move_shark();
        reduce_smell();
        check_shark();
        if(is_end()) break;
    }
    cout << time;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int num;
            cin >> num;
            if(num > 0)
            {
                shark[num].r = i, shark[num].c = j;
                shark_map[i][j].push_back(num);
                smell[i][j].first = num;
                smell[i][j].second = K;
            }
        }
    }

    for(int i=1; i<=M; i++)
        cin >> shark[i].dir;
    
    for(int i=1; i<=M; i++)
        for(int j=1; j<=4; j++)
            for(int k=1; k<=4; k++)
                cin >> shark[i].D[j][k];
}
int main()
{
    input();
    solve();
    return 0;
}
