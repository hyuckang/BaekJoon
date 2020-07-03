#include<iostream>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M, fuel;
int map_[25][25], vist[25][25], st_map[25][25];
map<pair<int, int>, pair<int, int>> dst_map;
int taxi_r, taxi_c;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int move_bfs()
{
    pair<int, int> dst = dst_map[make_pair(taxi_r, taxi_c)];
    
    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    vist[taxi_r][taxi_c] = 0;
    Q.push(make_pair(taxi_r, taxi_c));
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(map_[nr][nc] || vist[nr][nc] >= 0) continue;
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            Q.push(make_pair(nr, nc));
            // 도착한 경우
            if(nr == dst.first && nc == dst.second)
            {
                if(vist[nr][nc] > fuel)
                    return -1;
                else
                {
                    fuel += vist[nr][nc];
                    taxi_r = nr, taxi_c = nc;
                    M--;
                    return 1;
                }
            }
        }
    }
    return -1;
}
int find_bfs()
{
    // 택시에 태웠다면, st맵에서 지우고, fuel 계산하고, ride_num을 손님번호로
    // 태우지 못한다면 return -1
    if(st_map[taxi_r][taxi_c] > 0)
    {
        st_map[taxi_r][taxi_c] = 0;
        return 1;
    }
    
    memset(vist, -1, sizeof(vist));
    vector<tuple<int, int, int, int>> V; // {cost, r, c, num}
    queue<pair<int, int>> Q;
    vist[taxi_r][taxi_c] = 0;
    Q.push(make_pair(taxi_r, taxi_c));
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 1 || nr > N || nc < 1 || nc > N) continue;
            if(map_[nr][nc] || vist[nr][nc] >= 0) continue;
            Q.push(make_pair(nr, nc));
            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            if(st_map[nr][nc] > 0)
            {
                V.push_back(make_tuple(vist[nr][nc], nr, nc, st_map[nr][nc]));
            }
        }
    }

    // 아무도 태우지 못함
    if(V.size() == 0) return -1;
    // 거리순, 행순, 열순 정렬
    sort(V.begin(), V.end());

    int cus_cost, cus_r, cus_c, cus_num;
    tie(cus_cost, cus_r, cus_c, cus_num) = V.at(0);
    if(cus_cost > fuel)
        return -1;
    else
    {
        taxi_r = cus_r, taxi_c = cus_c;
        fuel -= cus_cost;
        st_map[taxi_r][taxi_c] = 0;
        return 1;
    }
}
int solve()
{
    while(true)
    {
        if(M == 0) return fuel;

        if(find_bfs() == -1)
            return -1;
        else if(move_bfs() == -1)
            return -1;
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> fuel;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin >> map_[i][j];

    cin >> taxi_r >> taxi_c;
    for(int i=1; i<=M; i++)
    {
        pair<int, int> st, dst;
        cin >> st.first >> st.second >> dst.first >> dst.second;
        st_map[st.first][st.second] = i;
        dst_map[st] = dst;
    }
}
int main()
{
    input();
    cout << solve();
    return 0;
}
