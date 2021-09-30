/*
    위상 정렬
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct INFO
{   
    // build_time : i번째 건물을 짓는데 걸리는시간
    // ex_time : i번째 건물을 짓기 위한 다른 건물을 짓는 시간 중 최댓값
    int in_degree = 0, build_time = 0, max_ex_time = 0;
};
int N;
INFO info[505];
vector<int> V[505];
bool vist[505];
void solve()
{
    // 진입차수가 0인 정점을 큐에 넣기
    queue<int> Q;
    for(int i=1; i<=N; i++)
    {
        if(info[i].in_degree == 0)
        {
            vist[i] = true;
            Q.push(i);
        }
    }

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(int i=1; i<=N; i++)
        {
            if(vist[i]) continue;
            
            // 간선 탐색
            int e_sz = V[i].size();
            for(int e=0; e<e_sz; e++)
            {
                if(V[i].at(e) == cur)
                {
                    // A(10) -> B, C(15) -> B 일 경우
                    // B는 절대적으로 15초 이후에나 지을수 있음
                    info[i].max_ex_time = max(info[i].max_ex_time, info[cur].max_ex_time + info[cur].build_time);
                    info[i].in_degree--;
                    if(info[i].in_degree == 0)
                    {
                        vist[i] = true;
                        Q.push(i);
                    }
                }
            }
        }
    }
    
    for(int i=1; i<=N; i++) cout<<info[i].build_time + info[i].max_ex_time<<"\n";
}
void input()
{
    cin>>N;
    int tmp_input = 0;
    for(int i=1; i<=N; i++)
    {
        cin>>info[i].build_time;
        while(true)
        {
            cin>>tmp_input;
            if(tmp_input == -1) break;
            V[i].push_back(tmp_input);
            info[i].in_degree++;
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
