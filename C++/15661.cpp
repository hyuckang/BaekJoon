#include <iostream>
#include <vector>
using namespace std;

int N, stat[25][25], min_res = 987654321;

int calc(vector<int> &start)
{
    bool select[25] = {false};
    for(auto it : start)
        select[it] = true;

    int start_res = 0, link_res = 0;   
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(i == j) continue;
            if(select[i] && select[j])
                start_res += stat[i][j];
            else if(!select[i] && !select[j])
                link_res += stat[i][j];
        }
    }

    return abs(start_res - link_res);
}
void go(int idx, int cnt, int goal, vector<int> &start)
{
    if(idx > N) return;
    
    if(cnt == goal)
    {
        min_res = min(min_res, calc(start));   
        return;
    }

    start.push_back(idx);
    go(idx + 1, cnt + 1, goal, start);
    start.pop_back();
    go(idx + 1, cnt, goal, start);
}
int main()
{
    // input
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int r=0; r<N; r++)
        for(int c=0; c<N; c++)
            cin >> stat[r][c];

    // solve
    for(int goal=1; goal<N; goal++)
    {
        vector<int> start;
        go(0, 0, goal, start);
    }

    cout << min_res;

    return 0;
}
