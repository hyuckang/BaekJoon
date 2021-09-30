#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
char map[15][15];
bool vist[15][15];
int pop_cnt = 0, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void block_down()
{
    for(int c=0; c<6; c++)
    {
        for(int r=11; r>0; r--)
        {
            if(map[r][c] == '.' && map[r-1][c] != '.')
            {
                swap(map[r][c], map[r-1][c]);
                
                if(r <= 10) r = r+2;
                else if(r == 10) r = 12;
                else if(r == 11) continue;
            }
        }
    }
}

void dfs(int r, int c, vector<pair<int, int>> &pop_blocks)
{
    pop_blocks.push_back(make_pair(r, c));
    vist[r][c] = true;

    for(int dir=0; dir<4; dir++)
    {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if(nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
        if(map[r][c] != map[nr][nc]) continue;
        if(map[nr][nc] == '.' || vist[nr][nc]) continue;

        dfs(nr, nc, pop_blocks);
    }
}

void solve()
{
    while(true)
    {
        memset(vist, false, sizeof(vist));
        bool is_pop = false;

        for(int r=0; r<12; r++)
        {
            for(int c=0; c<6; c++)
            {
                if(map[r][c] == '.' || vist[r][c]) continue;
                
                vector<pair<int, int>> pop_blocks;
                dfs(r, c, pop_blocks);

                if(pop_blocks.size() >= 4)
                {
                    is_pop = true;  // 터졌다고 표시
                    int block_cnt = pop_blocks.size();
                    for(int i=0; i<block_cnt; i++)
                    {
                        map[pop_blocks[i].first][pop_blocks[i].second] = '.';
                    }
                }
            }
        }
    
        if(is_pop)
        {   
            pop_cnt++;
            block_down();
        }
        else break;
    }
    cout<<pop_cnt;
}

void input()
{
    for(int r=0; r<12; r++)
    {
        for(int c=0; c<6; c++)
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
