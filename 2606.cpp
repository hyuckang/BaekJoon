#include<iostream>
#include<vector>
using namespace std;

int N, M, res = 0;
bool vist[105];
vector<int> edge[105];

void dfs(int V)
{
    vist[V] = true;
    res++;
    int e_sz = edge[V].size();
    for(int i=0; i<e_sz; i++)
    {
        if(!vist[edge[V].at(i)])
        {
            dfs(edge[V].at(i));
        }
    }
}
void solve()
{
    dfs(1);
    cout << res - 1;
}
void input()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}
int main()
{
    input();
    solve();
    return 0;
}
