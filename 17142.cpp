#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
int N, M;
int virus_cnt, empty_cnt;
int time, min_res = 0;
int map[55][55], vist[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<pair<int, int>> viruss;
bool select_virus[15];

void input();
void pr_map();
void pr_vist();
void bfs()
{
    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    for(int i=0; i<virus_cnt; i++)
    {
        vist[viruss[i].first][viruss[i].second] = 0;
        if(select_virus[i])
        {
            Q.push({viruss[i].first, viruss[i].second});
        }
    }
    time = 0;

}
void go(int cnt, int idx)
{
    if(idx > virus_cnt)
    {
        return;
    }
    
    if(cnt == M)
    {
        // M개 선택 -> bfs 호출
        bfs();
        // pr_vist();
        // getchar();
        return;
    }

    select_virus[idx] = true;
    go(cnt+1, idx+1);
    select_virus[idx] = false;
    go(cnt, idx+1);
}
int solve()
{
    go(0, 0);
    return -1;
}
int main()
{
    input();
    cout<<solve();
    return 0;
}
void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 2)
            {
                viruss.push_back({i, j});
                virus_cnt++;
            }
            else if(map[i][j] == 0)
            {
                empty_cnt++;
            }
        }
    }
}
void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void pr_vist()
{
    cout<<"=== vist ===\n";
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<vist[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
