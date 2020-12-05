#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int K, V, E;
int vist[20005];
vector<int> Edge[20005];

bool bfs(int V)
{
    // 이미 방문 했는데 색깔이 같다면 이분 그래프 X
    // 이분그래프가 아니라면 return false, 이분그래프라면 return true
    // 빨강 : 1, 파랑 : 2 으로 색칠
    queue<int> Q;
    Q.push(V);
    vist[V] = 1;

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(size_t i=0; i<Edge[cur].size(); i++)
        {
            int next_V = Edge[cur].at(i);
            // 방문하지 않았다면, 큐에 넣는다
            if(vist[next_V] == 0)
            {
                Q.push(next_V);
                vist[next_V] = 3 - vist[cur];
            }
            // 방문했는데 cur과 색깔이 같다면 이분그래프 X
            else if(vist[next_V] == vist[cur])
                return false;
        }
    }
    return true;
}
void solve()
{
    for(int i=1; i<=V; i++)
    {        
        // 방문하지 않은 정점마다 BFS 호출
        if(vist[i] == 0)
        {
            if(!bfs(i))
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    int a, b;
    for(int i=0; i<E; i++)
    {
        cin >> a >> b;
        Edge[a].push_back(b);
        Edge[b].push_back(a);
    }
}
void init()
{
    memset(vist, 0, sizeof(vist));
    for(int i=0; i<20005; i++)
        Edge[i].clear();
}
int main()
{
    cin >> K;
    while(K--)
    {
        init();
        input();
        solve();
    }
    return 0;
}
