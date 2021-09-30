#include<iostream>
using namespace std;

int N, M, A[100005];

void solve()
{
    for(int i=1; i<=N; i++)
    {
        cin>>A[i];
        A[i] += A[i - 1];
    }

    int i, j;
    for(int k=0; k<M; k++)
    {   
        cin>>i>>j;
        cout<<A[j] - A[i - 1]<<"\n";
    }
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
}
int main()
{
    input();
    solve();
    return 0;
}
