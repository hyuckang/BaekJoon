#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
struct NODE
{
    int x, y;
};
int T, N;
NODE node[105];
vector<int> V[105];
bool end_flag, vist[105];

void dfs(int v)
{
    if(v == N+1)
    {
        end_flag = true;
        return;
    }

    vist[v] = true;

    int edge_sz = V[v].size();
    for(int i=0; i<edge_sz; i++)
    {
        if(vist[V[v].at(i)]) continue;
        dfs(V[v].at(i));
    }
}
bool dist(int v1, int v2)
{   
    // v1과 v2의 거리가 1000 이하면 return true, 이상이면 return false
    int val = abs(node[v1].x - node[v2].x) + abs(node[v1].y - node[v2].y);
    if(val <= 1000) return true;
    else return false;
}
void solve()
{
    // 간선 그리기
    for(int i=0; i<N+2; i++)
    {
        for(int j=0; j<N+2; j++)
        {
            if(i == j) continue;
            if(dist(i, j))
            {
                V[i].push_back(j);
            }
        }
    }

    dfs(0);

    if(end_flag) cout<<"happy\n";
    else cout<<"sad\n";
}
void input()
{
    cin>>N;
    for(int i=0; i<N+2; i++) cin>>node[i].x>>node[i].y;
}
void init()
{
    for(int i=0; i<105; i++) V[i].clear();
    memset(vist, false, sizeof(vist));
    end_flag = false;
}
int main()
{
    cin>>T;
    while(T--)
    {
        init();
        input();
        solve();
    }
    return 0;
}
