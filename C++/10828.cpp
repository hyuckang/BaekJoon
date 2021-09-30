#include<iostream>
#include<stack>
using namespace std;
int N;
void solve()
{
    stack<int> S;
    string cmd;
    int X;
    for(int i=0; i<N; i++)
    {
        cin>>cmd;
        if(cmd == "push")
        {
            cin>>X;
            S.push(X);
        }
        else if(cmd == "pop")
        {
            if(S.empty()) cout<<-1<<"\n";
            else
            {
                cout<<S.top()<<"\n";
                S.pop();
            }
        }
        else if(cmd == "size")
        {
            cout<<S.size()<<"\n";
        }
        else if(cmd == "empty")
        {
            if(S.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if(cmd == "top")
        {
            if(S.empty()) cout<<-1<<"\n";
            else cout<<S.top()<<"\n";
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
