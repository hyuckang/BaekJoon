#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M, res = 0;
char map[505][505];
// vist : 사이클 방지
// vist가 표시되어있다면, can_out 또는 cant_out에 표시되어있음
bool vist[505][505], can_out[505][505], cant_out[505][505];

void go(int r, int c, vector<pair<int, int>> &route)
{
    // 나갔거나, 나갈수 있거나
    if((r < 0 || r >= N || c < 0 || c >= M) || can_out[r][c])
    {
        res++;
        int route_sz = route.size();
        for(int i=0; i<route_sz; i++)
        {
            can_out[route[i].first][route[i].second] = true;
        }
        return;
    }
    // 나갈수 없거나, 사이클일 경우
    else if(cant_out[r][c] || vist[r][c])
    {
        int route_sz = route.size();
        for(int i=0; i<route_sz; i++)
        {
            cant_out[route[i].first][route[i].second] = true;
        }
        return;
    }

    vist[r][c] = true;
    route.push_back(make_pair(r, c));
    
    if(map[r][c] == 'U') go(r - 1, c, route);
    else if(map[r][c] == 'R') go(r, c + 1, route);
    else if(map[r][c] == 'D') go(r + 1, c, route);
    else if(map[r][c] == 'L') go(r, c - 1, route);
}
void solve()
{
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            vector<pair<int, int>> route;
            go(r, c, route);
        }
    }
    cout<<res;
}
void input()
{
    cin>>N>>M;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            cin>>map[r][c];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
