#include<iostream>
#include<algorithm>
using namespace std;

int N, A[10];
int max_res = -987654321;
int calc()
{
    int res = 0;
    for(int i=0; i <N-1; i++) res += abs(A[i] - A[i + 1]);
    return res;
}
void solve()
{
    // 순열로 모든 경우의 수를 시도하기 때문에 정렬해주어야 함
    sort(A, A+N);

    do
    {
        max_res = max(max_res, calc());
    } while(next_permutation(A, A + N));

    cout<<max_res;
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
