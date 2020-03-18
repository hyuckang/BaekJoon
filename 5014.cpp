#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int F, S, G, U, D;
int vist[1000011];
void solve()
{
    queue<int> Q;
    vist[S] = 0;
    Q.push(S);   
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if(cur == G)
        {
            cout<<vist[G];
            return;
        }
        if(cur + U <= F && vist[cur + U] == -1)
        {
            Q.push(cur + U);
            vist[cur + U] = vist[cur] + 1;
        }
        if(cur - D >= 1 && vist[cur - D] == -1)
        {
            Q.push(cur - D);
            vist[cur - D] = vist[cur] + 1;
        }
    }
    cout<<"use the stairs";
}
void input()
{
    cin>>F>>S>>G>>U>>D;
}
void init()
{
    memset(vist, -1, sizeof(vist));
}
int main()
{   
    init();
    input();
    solve();
    return 0;
}
