#include<iostream>
#include<deque>
using namespace std;
int N;
void solve()
{
    deque<int> DQ;
    string cmd;
    int X;
    for(int i=0; i<N; i++)
    {
        cin>>cmd;
        if(cmd == "push_front")
        {
            cin>>X;
            DQ.push_front(X);
        }
        else if(cmd == "push_back")
        {
            cin>>X;
            DQ.push_back(X);
        }
        else if (cmd == "pop_front")
        {
            if(DQ.empty()) cout<<-1<<"\n";
            else
            {
                cout<<DQ.front()<<"\n";
                DQ.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if(DQ.empty()) cout<<-1<<"\n";
            else
            {
                cout<<DQ.back()<<"\n";
                DQ.pop_back();
            }
            
        }
        else if (cmd == "size")
        {
            cout<<DQ.size()<<"\n";
        }
        else if (cmd == "empty")
        {
            if(DQ.empty()) cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else if (cmd == "front")
        {
            if(DQ.empty()) cout<<-1<<"\n";
            else cout<<DQ.front()<<"\n";
        }
        else if (cmd == "back")
        {
            if(DQ.empty()) cout<<-1<<"\n";
            else cout<<DQ.back()<<"\n";
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
