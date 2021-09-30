#include<iostream>
#include<queue>
using namespace std;
int N;
void solve()
{
    queue<int> Q;
    string cmd;
    int X;
    for(int i=0; i<N; i++)
    {
        cin>>cmd;
        if(cmd == "push")
        {
            cin>>X;
            Q.push(X);
        }
        else if (cmd == "pop")
        {
            if(Q.empty()) cout<<-1<<"\n";
            else
            {
                cout<<Q.front()<<"\n";
                Q.pop();
            }
        }
        else if(cmd == "size")
        {
            cout<<Q.size()<<"\n";
        }
        else if(cmd == "empty")
        {
            if(Q.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";            
        }
        else if(cmd == "front")
        {
            if(Q.empty()) cout<<-1<<"\n";
            else cout<<Q.front()<<"\n";
        }
        else if(cmd == "back")
        {
            if(Q.empty()) cout<<-1<<"\n";
            else cout<<Q.back()<<"\n";
        }
    }
}
void input()
{
    cin>>N;
}
int main()
{
    input();
    solve();
    return 0;
}
