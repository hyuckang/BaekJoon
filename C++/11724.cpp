#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> edge[1005];
bool vist[1005];

void dfs(int V)
{   
    vist[V] = true;
    int e_sz = edge[V].size();
    for(int E=0; E<e_sz; E++)
    {
        if(!vist[edge[V].at(E)])
            dfs(edge[V].at(E));
    }
}
void solve()
{
    int cnt = 0;
    for(int V=1; V<=N; V++)
    {
        if(!vist[V])
        {
            dfs(V);
            cnt++;
        }
    }
    cout << cnt;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
}
int main()
{
    input();
    solve();
    return 0;
}
