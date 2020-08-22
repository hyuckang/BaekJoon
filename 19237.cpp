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
vector<int> map[25][25];
pair<int, int> smell[25][25];
int dr[] = {0, -1, 1, 0, 0}, dc[] = {0, 0, 0, -1, 1};
NODE shark[405];

bool is_end()
{
    if(time > 1000)
    {
        time = -1;
        return true;
    }
}

void check()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int sz = map[i][j].size();
            if(sz > 1)
            {
                sort(map[i][j].begin(), map[i][j].end());
                for(int x=0; x<sz-1; x++)
                {
                    shark[map[i][j].back()].end = true;
                    map[i][j].pop_back();
                }
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
            if(0 < smell[i][j].second && smell[i][j].second < K)
            {
                smell[i][j].second--;
                if(smell[i][j].second == 0)
                    smell[i][j].first = 0;
            }
        }
    }
}
void pr_map()
{
    cout << "=== map ===\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout << map[i][j].at(0) << " ";
        }
        cout << "\n";
    }
}
void pr_smell()
{
    cout << "=== smell ===\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout << smell[i][j].second << " ";
        }
        cout << "\n";
    }
}
void pr_shark()
{
    cout << "=== shark ===\n";
    for(int i=1; i<=M; i++)
    {
        cout << "r : " << shark[i].r << ", c : " << shark[i].c << ", dir : " << shark[i].dir << "\n";
        for(int j=1; j<=4; j++)
        {
            for(int k=1; k<=4; k++)
            {
                cout << shark[i].D[j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void move()
{
    for(int x=1; x<=M; x++)
    {
        if(shark[x].end) continue;
        
        // 냄새 없는 칸 갯수 세기
        vector<int> cnt1;
        for(int i=1; i<4; i++)
        {
            int nr = shark[x].r + dr[i];
            int nc = shark[x].c + dc[i];
            if(nr <= 0 || nr > N || nc <= 0 || nc > N)
            {
                cnt1.push_back(-1);
                continue;
            }
            if(smell[nr][nc].second > 0)
            {
                cnt1.push_back(1);
                continue;
            }
        }
        // 냄새가 없는 칸이 없으면
        if(cnt1.size() == 4)
        {
            vector<int> cnt2;
            for(int i=1; i<=4; i++)
            {

            }
        }
        // 냄새가 없는 칸이 있으면
        else
        {
            for(int i=1; i<4; i++)
            {
                int nr = shark[x].r + dr[ shark[x].D[shark[x].dir][i] ];
                int nc = shark[x].c + dc[ shark[x].D[shark[x].dir][i] ];
                if(nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
                if(smell[nr][nc].second > 0) continue;
                
                map[shark[x].r][shark[x].c].pop_back();
                map[nr][nc].push_back(x);
                shark[x].r = nr, shark[x].c = nc, shark[x].dir = shark[x].D[shark[x].dir][i];
                break;
            }
            
        }
    }
}
void solve()
{
    move();
    pr_map();
    pr_shark();
}
void input()
{
    /*
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    */
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int num;
            cin >> num;
            map[i][j].push_back(num);
            smell[i][j].first = num;
            smell[i][j].second = K;
            if(map[i][j].at(0) > 0)
            {
                shark[map[i][j].at(0)].r = i, shark[map[i][j].at(0)].c = j;
            }
        }
    }

    for(int i=1; i<=M; i++)
        cin >> shark[i].dir;

    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=4; j++)
        {
            for(int k=1; k<=4; k++)
            {
                cin >> shark[i].D[j][k];
            }
        }
    }

    /*
    pr_map();
    pr_smell();
    pr_shark();
    */
}
int main()
{
    input();
    cout << "==============solve====================\n";
    solve();
    return 0;
}
