#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int N;
int map[110];
bool vist[110];
vector<int> res;
// i에서 시작해서 다시 i로 돌아온다면 -> 정답 벡터에 넣어준다.
void dfs(int start_v, int cur_v)
{
    if(!vist[cur_v])
    {
        vist[cur_v] = true;
        dfs(start_v, map[cur_v]);
    }
    else
    {
        if(start_v == cur_v) res.push_back(start_v);
        else return;
    }
}
void solve()
{
    for(int i=1; i<=N; i++)
    {
        memset(vist, false, sizeof(vist));
        dfs(i, i);
    }

    int res_sz = res.size();
    cout<<res_sz<<"\n";
    for(int i=0; i<res_sz; i++) cout<<res[i]<<"\n";
}
void input()
{
    cin>>N;
    for(int i=1; i<=N; i++) cin>>map[i];
}
int main()
{
    input();
    solve();
    return 0;
}
