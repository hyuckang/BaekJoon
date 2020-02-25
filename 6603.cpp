#include<iostream>
#include<cstring>
using namespace std;

int K;
int nums[13];
bool issued[13];

void go(int cnt, int idx)
{
    // 숫자를 모두 선택하였으면 출력한다.
    if(cnt == 6)
    {   
        for(int i=0; i<K; i++)
        {
            if(issued[i])
            {
                cout<<nums[i]<<" ";
            }
        }
        cout<<"\n";
        return;
    }

    // idx가 K 이상이 될 때 까지 6개를 선택하지 못하면 종료한다.
    if(K <= idx)
    {
        return;
    }

    // idx번째 숫자를 선택
    issued[idx] = true;
    go(cnt+1 , idx+1);
    issued[idx] = false;

    // idx번째 숫자를 선택하지 않음
    go(cnt, idx+1);

}

void init()
{
    memset(issued, false, sizeof(issued));
}

void input()
{
    for(int i=0; i<K; i++)
    {
        cin>>nums[i];
    }
}

void solve()
{
    go(0, 0);
    cout<<"\n";
}

int main()
{
    while(true)
    {
        cin>>K;
        if(K == 0) break;

        init();
        input();
        solve();
    }
    return 0;
}
