/*
    1. 인구 이동이 일어나는지 검사
    2. bfs로 연합 구하기
    3. 인구 이동 -> 연합을 vector에 넣어두고, bfs가 끝날 때 마다 이동시킨다
*/
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N, L, R, res = 0;
int map[55][55], vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

bool is_move()
{   
    // 인구 이동이 일어나면 true, 일어나지 않으면 false
    // 행 검사
    for(int i=0; i<N-1; i++)
    {   
        for(int j=0; j<N; j++)
        {
            if(L <= abs(map[i][j] - map[i+1][j]) && abs(map[i][j] - map[i+1][j]) <= R)
                return true;
        }
    }
    // 열 검사
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N-1; j++)
        {
            if(L <= abs(map[i][j] - map[i][j+1]) && abs(map[i][j] - map[i][j+1]) <= R)
                return true;
        }
    }
    return false;
}
void bfs(int r, int c, int cnt)
{
    // 하나의 연합이 생성 될 때마다 인구를 이동시킨다.
    int people_sum = 0;
    vector<pair<int, int>> nations;

    // 연합 구하기
    queue<pair<int, int>> Q;
    vist[r][c] = cnt;
    Q.push(make_pair(r, c));
    people_sum += map[r][c];
    nations.push_back(make_pair(r, c));

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N || vist[nr][nc] > -1) continue;
            if(L <= abs(map[cur.first][cur.second] - map[nr][nc]) && abs(map[cur.first][cur.second] - map[nr][nc]) <= R)
            {
                vist[nr][nc] = cnt;
                Q.push(make_pair(nr, nc));
                nations.push_back(make_pair(nr, nc));
                people_sum += map[nr][nc];
            }
        }
    }

    // 인구 이동
    int people_avg = people_sum / nations.size();
    for(int i=0; i<nations.size(); i++)
    {
        map[nations[i].first][nations[i].second] = people_avg;
    }
}
void solve()
{
    while(true)
    {
        // 인구 이동 검사
        if(!is_move()) break;
        res++;

        // 연합 구하고, 인구 이동
        int cnt = 0;
        memset(vist, -1, sizeof(vist));
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(vist[i][j] == -1)
                {
                    bfs(i, j, cnt);
                    cnt++;
                }
            }
        }
    }
    cout<<res;
}
void input()
{
    cin>>N>>L>>R;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
