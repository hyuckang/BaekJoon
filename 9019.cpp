#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int T, A, B;
int vist[10005];

void solve()
{
    string cmd[10005];
    queue<int> Q;
    vist[A] = 0;
    Q.push(A);

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if(cur == B)
        {
            int cmd_sz = cmd[B].size();
            for(int i=0; i<cmd_sz; i++)
            {
                cout << cmd[B].at(i);
            }
            cout << "\n";
            return;
        }

        int next;
        // D
        next = (2 * cur) % 10000;
        if(vist[next] == -1)
        {
            vist[next] = vist[cur] + 1;
            cmd[next] = cmd[cur] + 'D';
            Q.push(next);    
        }

        // S
        if(cur == 0)
            next = 9999;
        else
            next = cur - 1;
        if(vist[next] == -1)
        {
            vist[next] = vist[cur] + 1;
            cmd[next] = cmd[cur] + 'S';
            Q.push(next);
        }

        // L
        next = (cur % 1000) * 10 + (cur / 1000);
        if(vist[next] == -1)
        {
            vist[next] = vist[cur] + 1;
            cmd[next] = cmd[cur] + 'L';
            Q.push(next);
        }

        // R
        next = (cur % 10) * 1000 + (cur / 10);
        if(vist[next] == -1)
        {
            vist[next] = vist[cur] + 1;
            cmd[next] = cmd[cur] + 'R';
            Q.push(next);
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> A >> B;
}
int main()
{
    cin >> T;
    while(T--)
    {
        memset(vist, -1, sizeof(vist));
        input();
        solve();
    }
}
