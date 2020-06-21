#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

int N, vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
string map[55];

void solve()
{
    memset(vist, -1, sizeof(vist));

    deque<pair<int, int>> DQ;
    DQ.push_back(make_pair(0, 0));
    vist[0][0] = 0;

    while(!DQ.empty())
    {
        pair<int, int> cur = DQ.front(); DQ.pop_front();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir];
            int nc = cur.second + dc[dir];
            if(nr < 0 || nr >=N || nc < 0 || nc >= N || vist[nr][nc] > -1) continue;
            
            if(map[nr][nc] == '1')
            {
                DQ.push_front(make_pair(nr, nc));
                vist[nr][nc] = vist[cur.first][cur.second];
            }
            else
            {
                DQ.push_back(make_pair(nr, nc));
                vist[nr][nc] = vist[cur.first][cur.second] + 1;
            }
        }
    }

    cout << vist[N-1][N-1];
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
