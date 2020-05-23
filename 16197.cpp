#include<iostream>
#include<vector>
using namespace std;

#define r first
#define c second

int N, M, min_res = 987654321;
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
char map[25][25];
vector<pair<int, int>> coin;

void go(int cmd_cnt)
{
    if(cmd_cnt > 10) return;
    
    // 종료검사
    bool coin_1_flag = false;
    bool coin_2_flag = false;
    
    if(0 > coin[0].r || coin[0].r >= N || 0 > coin[0].c || coin[0].c >= M) coin_1_flag = true;
    if(0 > coin[1].r || coin[1].r >= N || 0 > coin[1].c || coin[1].c >= M) coin_2_flag = true;
    
    if(coin_1_flag && coin_2_flag) return;
    if(coin_1_flag || coin_2_flag)
    {
        min_res = min(min_res, cmd_cnt);
        return;
    }

    // 백트래킹
    for(int dir=0; dir<4; dir++)
    {
        int coin_1_nr = coin[0].r + dr[dir], coin_1_nc = coin[0].c + dc[dir];
        int coin_2_nr = coin[1].r + dr[dir], coin_2_nc = coin[1].c + dc[dir];
            
        if(map[coin_1_nr][coin_1_nc] == '#' && map[coin_2_nr][coin_2_nc] == '#') continue;

        int coin_1_tmp_r = coin[0].r, coin_1_tmp_c = coin[0].c;
        int coin_2_tmp_r = coin[1].r, coin_2_tmp_c = coin[1].c;
        if(map[coin_1_nr][coin_1_nc] != '#')
        {
            coin[0].first = coin_1_nr, coin[0].second = coin_1_nc;
        }
        if(map[coin_2_nr][coin_2_nc] != '#')
        {
            coin[1].first = coin_2_nr, coin[1].second = coin_2_nc;
        }

        go(cmd_cnt + 1);
        coin[0].first = coin_1_tmp_r, coin[0].second = coin_1_tmp_c;
        coin[1].first = coin_2_tmp_r, coin[1].second = coin_2_tmp_c;
    }
}
void solve()
{
    go(0);
    if(min_res == 987654321) cout<<-1;
    else cout<<min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 'o') coin.push_back(make_pair(i, j));
        }
    } 
}
int main()
{
    input();
    solve();
    return 0;
}
