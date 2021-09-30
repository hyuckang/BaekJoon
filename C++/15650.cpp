#include<iostream>
using namespace std;
int N, M;
int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8};
bool isused[10];
void go(int cnt, int idx)
{
    if(idx > N)
    {
        return;
    }

    if(cnt == M)
    {
        for(int i=0; i<N; i++)
        {
            if(isused[i]) cout<<nums[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    isused[idx] = true;
    go(cnt+1, idx+1);
    isused[idx] = false;
    go(cnt, idx+1);
}
void input()
{
    cin>>N>>M;
}
void solve()
{
    go(0, 0);
}
int main()
{
    input();
    solve();
    return 0;
}
