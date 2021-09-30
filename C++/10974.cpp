#include<iostream>
#include<algorithm>

using namespace std;
int N, A[10] = {1, 2, 3, 4, 5, 6, 7, 8};

void solve()
{
    do
    {
        for(int i=0; i<N; i++) cout<<A[i]<<" ";
        cout<<"\n";
    } while(next_permutation(A, A + N)); 
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
