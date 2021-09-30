/*
    순열을 구하는 문제
*/
#include<iostream>
#include<vector>
using namespace std;
int N, M;
int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8};
bool isused[10];
void go(int cnt, vector<int> &A)
{
    if(cnt == M)
    {
        for(int i=0; i<M; i++)
        {
            cout<<A[i]<<" "; 
        }
        cout<<"\n";
    }

    for(int i=0; i<N; i++)
    {
        if(isused[i]) continue;

        isused[i] = true;
        A.push_back(nums[i]);
        go(cnt+1, A);
        isused[i] = false;
        A.pop_back();
    }

}
void input()
{
    cin>>N>>M;
}
void solve()
{
    vector<int> A;
    go(0, A);
}
int main()
{
    input();
    solve();
    return 0;
}
