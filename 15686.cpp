#include<iostream>
#include<vector>
using namespace std;
int N, M;
int house_cnt, chicken_cnt, min_res = 987654321;
int map[55][55];
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken;
bool selected_chicken[15];

int calc()
{
    vector<int> city_chicken_dist;
    for(int i=0; i<house_cnt; i++)
    {
        int chicken_dist = 987654321;
        for(int j=0; j<chicken_cnt; j++)
        {
            if(selected_chicken[j])
            {
            chicken_dist = min(chicken_dist, abs(houses[i].first - chicken[j].first) + abs(houses[i].second - chicken[j].second));
            }
        }
        city_chicken_dist.push_back(chicken_dist);
    }
    int sum_res = 0;
    for(int i=0; i<house_cnt; i++)
    {
        sum_res += city_chicken_dist[i];
    }
    return sum_res;
}
void go(int cnt, int idx)
{
    if(cnt == M)
    {
        min_res = min(min_res, calc());
        return;
    }
    if(idx >= chicken_cnt)
    {
        return;
    }

    selected_chicken[idx] = true;
    go(cnt + 1, idx + 1);
    selected_chicken[idx] = false;
    go(cnt, idx + 1);
}
void input()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 1)
            {
                houses.push_back({i ,j});
                house_cnt++;
            }
            else if(map[i][j] == 2)
            {
                chicken.push_back({i, j});
                chicken_cnt++;
            }
        }
    }
}
void solve()
{
    go(0,0);
    cout<<min_res;
}
int main()
{
    input();
    solve();
    return 0;
}
