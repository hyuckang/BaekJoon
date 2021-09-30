#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct NODE
{
    int in = 0;
    vector<int> out;
};
int N, M;
NODE topol[32005];
bool vist[32005];

void solve()
{
    queue<int> Q;
    while(Q.size() < N)
    {
        for(int i=1; i<=N; i++)
        {
            if(!vist[i] && topol[i].in == 0)
            {
                Q.push(i);
                vist[i] = true;
                int out_sz = topol[i].out.size();
                for(int j=0; j<out_sz; j++)
                {
                    topol[topol[i].out.at(j)].in--;
                }
            }
        }
    }

    while(!Q.empty())
    {
        cout << Q.front() << " ";
        Q.pop();
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int A, B;
        cin >> A >> B;
        topol[A].out.push_back(B);
        topol[B].in++;
    }
}
int main()
{
    input();
    solve();
    return 0;
}
