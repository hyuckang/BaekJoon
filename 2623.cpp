#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct NODE
{
    int in = 0;
    vector<int> out;
    bool vist = false;
};
int N, M, cnt;
NODE singer[1005];

void solve()
{
    queue<int> Q;
    while(Q.size() < N)
    {
        int cycle_check = Q.size();
        for(int num=1; num<=N; num++)
        {
            if(singer[num].vist) continue;

            if(singer[num].in == 0)
            {
                Q.push(num);
                singer[num].vist = true;

                // out degree 처리
                int out_sz = singer[num].out.size();
                for(int sz=0; sz<out_sz; sz++)
                {
                    singer[singer[num].out[sz]].in--;
                }
            }
        }
        // 1 ~ N 까지 순회했지만, 큐 사이즈가 변함이 없다면 cycle 존재
        if(cycle_check == Q.size())
        {
            cout << 0;
            return;
        }
    }
    while(!Q.empty())
    {
        cout << Q.front() << "\n";
        Q.pop();
    }
}
void input()
{
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        cin >> cnt;
        int topol[1005];

        for(int j=0; j<cnt; j++)
            cin >> topol[j];

        for(int j=0; j<cnt-1; j++)
        {
            singer[topol[j]].out.push_back(topol[j+1]);
            singer[topol[j+1]].in++;
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
