#include<iostream>
#include<algorithm>
using namespace std;

int N, A[10005];

void solve()
{
    if(prev_permutation(A, A + N))
    {
        for(int i=0; i<N; i++) cout<<A[i]<<" ";
    }
    else cout<<-1<<"\n";
}
void input()
{
    cin>>N;
    for(int i=0; i<N; i++) cin>>A[i];
}
int main()
{
    input();
    solve();
    return 0;
}
