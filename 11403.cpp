#include<iostream>
#include<queue>
using namespace std;
int N;
int map[110][110], res[110][110];
vector<int> vertex[100];

void bfs(int start_v)
{
    queue<int> Q;
    int start_sz = vertex[start_v].size();
    for(int i=0; i<start_sz; i++)
    {
        Q.push(vertex[start_v][i]);
        res[start_v][vertex[start_v][i]] = 1;
    }

    while(!Q.empty())
    {
        int cur_v = Q.front(); Q.pop();
        int cur_sz = vertex[cur_v].size();
        for(int i=0; i<cur_sz; i++)
        {
            if(res[start_v][vertex[cur_v][i]]) continue;
            Q.push(vertex[cur_v][i]);
            res[start_v][vertex[cur_v][i]] = 1;
        }
    }
}
void solve()
{
    // 각 정점을 시작으로 BFS를 n번 돌려서 인접행렬을 채운다.
    for(int i=0; i<N; i++)
    {
        bfs(i);
    }

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int tmp;
            cin>>tmp;
            if(tmp == 1) vertex[i].push_back(j);
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
