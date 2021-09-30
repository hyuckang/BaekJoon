#include<iostream>
using namespace std;

int N, M, K;
int A[105][105], B[105][105], C[105][105];

void solve()
{
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<K; c++)
        {
            for(int i=0; i<M; i++)
            {
                C[r][c] += (A[r][i] * B[i][c]);
            }
        }
    }

    for(int r=0; r<N; r++)
    {
        for(int c=0; c<K; c++)
        {
            cout<<C[r][c]<<" ";
        }
        cout<<"\n";
    }
}
void input()
{
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            cin>>A[i][j];
        }
    }
    cin>>M>>K;
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<K; j++)
        {
            cin>>B[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
