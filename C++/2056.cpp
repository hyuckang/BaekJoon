#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct NODE
{
    int time, end_time = -1, in = 0;
    vector<int> in_list;
    vector<int> out_list;
};

int N;
NODE TASK[10005];

void solve()
{
    int cnt = 0;
    while(cnt < N)
    {
        queue<NODE> Q;
        for(int i=1; i<=N; i++)
        {
            if(TASK[i].in == 0 && TASK[i].end_time == -1)
            {
                Q.push(TASK[i]);
                cnt++;

                int before_max = -99999;
                for(auto X : TASK[i].in_list)
                    before_max = max(before_max, TASK[X].end_time);

                if(before_max == -99999)
                    TASK[i].end_time = TASK[i].time;
                else
                    TASK[i].end_time = TASK[i].time + before_max;
            }
        }

        while(!Q.empty())
        {
            NODE cur_node = Q.front(); Q.pop();
            for(auto X : cur_node.out_list)
                TASK[X].in--;
        }
    }

    int answer = -1;
    for(int i=1; i<=N; i++)
        answer = max(answer, TASK[i].end_time);
    cout << answer;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cin >> TASK[i].time >> TASK[i].in;
        for(int j=0; j<TASK[i].in; j++)
        {
            int in_node;
            cin >> in_node;
            TASK[i].in_list.push_back(in_node);
            TASK[in_node].out_list.push_back(i);
        }
    }
}
int main()
{
    // 'TASK 중 end_time이 가장 큰 값'이 '모든 작업을 완료하기 위한 최소시간'
    // A노드의 end_time은 A 노드의 in_list 중 end_time이 가장 큰 값에 A 노드의 time을 더한것
    input();
    solve();
    return 0;
}
