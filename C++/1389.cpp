#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N, M;
vector<int> map[115];
int vist[115];
int V_res, min_res = 987654321;
void BFS(int V)
{
    memset(vist, -1, sizeof(vist));

    queue<int> Q;
    Q.push(V);
    vist[V] = 0;
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        int cur_E_sz = map[cur].size();
        for(int i=0; i<cur_E_sz; i++)
        {
            int next = map[cur][i];
            if(vist[next] >= 0) continue;
            Q.push(next);
            vist[next] = vist[cur] + 1;
        }
    }
}
void solve()
{
    for(int i=1; i<=N; i++)
    {
        // BFS
        BFS(i);
        
        // 케빈 베이컨의 수 계산
        int bacon_sum = 0;
        for(int j=1; j<=N; j++) bacon_sum += vist[j];

        if(min_res > bacon_sum)
        {
            min_res = bacon_sum;
            V_res = i;
        }
    }
    cout<<V_res;
}
void input()
{
    cin>>N>>M;
    int A, B;
    for(int i=1; i<=M; i++)
    {
        cin>>A>>B;
        map[A].push_back(B);
        map[B].push_back(A);
    }
}
int main()
{
    input();
    solve();
    return 0;
}
