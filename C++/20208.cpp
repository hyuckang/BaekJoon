#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, H;
int MAP[15][15];

pair<int, int> HOME;
vector<pair<int, int>> MILK;
void solve()
{
    int max_res = 0; // 하나도 못 먹을 수 있기에 0

    do
    {
        pair<int, int> cur_loc = HOME;
        int cur_helth = M;

        for(int idx=0; idx<(int)MILK.size(); idx++)
        {
            int to_milk_dist = abs(cur_loc.first - MILK[idx].first) + abs(cur_loc.second - MILK[idx].second);
            
            // idx번째 우유까지 갈수 있으면, 이동하고, 체력 계산
            if(to_milk_dist <= cur_helth)
            {
                cur_loc = MILK[idx];
                cur_helth = cur_helth - to_milk_dist + H;

                // 이동한 위치에서, 집에 돌아갈수 있다면, 최대 값 갱신
                int to_home_dist = abs(cur_loc.first - HOME.first) + abs(cur_loc.second - HOME.second);
                if(to_home_dist <= cur_helth)
                    max_res = max(max_res, idx + 1);
            }
            // 갈 수 없다면, 순열 더이상 진행 불가
            else
                break;
        }
        
    } while(next_permutation(MILK.begin(), MILK.end()));

    cout << max_res;
}
void input()
{
    cin >> N >> M >> H;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            cin >> MAP[r][c];
            if(MAP[r][c] == 1)
                HOME.first = r, HOME.second = c;
            else if(MAP[r][c] == 2)
                MILK.push_back({r, c});
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
