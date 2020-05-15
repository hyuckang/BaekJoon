#include<iostream>
using namespace std;
// Prefix Sum
// D[i] : 1부터 i까지의 합을 저장
int N, M, D[100005];
void solve()
{
    cin>>M;
    int i, j;
    for(int k=0; k<M; k++)
    {
        cin>>i>>j;
        cout<<D[j] - D[i - 1]<<"\n"; 
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>D[i];
        D[i] += D[i - 1];
    }
}
int main()
{
    input();
    solve();
    return 0;
}
