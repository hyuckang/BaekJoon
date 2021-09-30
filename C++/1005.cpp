#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int in = 0, D = 0, build_time = 0;
    vector<int> out, in_time;
};

int TC, N, K, D, X, Y, W;
node NODE[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> TC;
    while(TC--)
    {
        // init
        for(int i=0; i<1005; i++)
        {
            NODE[i].in = 0, NODE[i].D = 0, NODE[i].build_time = 0;
            NODE[i].out.clear();
            NODE[i].in_time.clear();
        }

        // input
        cin >> N >> K;
        for(int i=1; i<=N; i++)
            cin >> NODE[i].D;

        for(int i=0; i<K; i++)
        {
            cin >> X >> Y;
            NODE[X].out.push_back(Y);
            NODE[Y].in++;
        }
        cin >> W;

        // solve
        queue<int> Q;
        while(true)
        {
            for(int i=1; i<=N; i++)
            {
                if(NODE[i].in == 0)
                    Q.push(i);
            }

            if(Q.empty()) break;

            while(!Q.empty())
            {
                int cur = Q.front(); Q.pop();
                // cur의 build time 계산
                if(NODE[cur].in_time.size() == 0)
                    NODE[cur].build_time = NODE[cur].D;
                else
                {
                    int max_in_time = -1;
                    for(auto tmp_in_time : NODE[cur].in_time)
                        max_in_time = max(max_in_time, tmp_in_time);
                    NODE[cur].build_time = NODE[cur].D + max_in_time;
                }

                for(auto out_node : NODE[cur].out)
                {
                    NODE[out_node].in--;
                    NODE[out_node].in_time.push_back(NODE[cur].build_time);
                }
                
                NODE[cur].in = -1;
            }
        }

        cout << NODE[W].build_time << "\n";
    }
    return 0;
}
