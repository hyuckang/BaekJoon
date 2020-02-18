#include<iostream>

using namespace std;
int N, pluss, minuss, mull, divv;
int max_res = -987654321, min_res = 987654321;
int nums[11], opers[10];

int calc()
{
    int calc_res = nums[0];
    for(int i=0; i<N-1; i++)
    {
        if(opers[i] == 1)
        {
            calc_res += nums[i+1];
        }
        else if(opers[i] == 2)
        {
            calc_res -= nums[i+1];
        }
        else if(opers[i] == 3)
        {
            calc_res *= nums[i+1];
        }
        else if(opers[i] == 4)
        {
            calc_res /= nums[i+1];
        }
    }
    return calc_res;
}

void go(int cnt, int go_pluss, int go_minuss, int go_mull, int go_divv)
{
    // cnt : 현재까지 선택한 연산자의 수
    // go_pluss, go_minuss, go_mull, go_divv : 현재까지 선택한 각 연산자의 갯수
    // plus 는 1로, minus 는 2로, mull는 3으로, div는 4로 나타냄 
    
    if(go_pluss > pluss || go_minuss > minuss || go_mull > mull || go_divv > divv)
    {
        // 현재 상태를 검사하기 전에 계산하면, 연산자를 초과해서 선택한 경우도 계산이 됨
        return;
    }

    if(cnt == N-1)
    {
        // 연산자를 선택완료
        int res = calc();        
        if(max_res < res)
        {
            max_res = res;
        }
        if(min_res > res)
        {
            min_res = res;
        }
    }
    
    if(pluss > 0)
    {
        opers[cnt] = 1;
        go(cnt+1, go_pluss+1, go_minuss, go_mull, go_divv);
        // opers[cnt] = 0;
    }

    if(minuss > 0)
    {
        opers[cnt] = 2;
        go(cnt+1, go_pluss, go_minuss+1, go_mull, go_divv);
        // opers[cnt] = 0;
    }

    if(mull > 0)
    {
        opers[cnt] = 3;
        go(cnt+1, go_pluss, go_minuss, go_mull+1, go_divv);
        // opers[cnt] = 0;
    }

    if(divv > 0)
    {
        opers[cnt] = 4;
        go(cnt+1, go_pluss, go_minuss, go_mull, go_divv+1);
        // opers[cnt] = 0;
    }
    
}

void input()
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>nums[i];
    }
    cin>>pluss>>minuss>>mull>>divv;
}

void solve()
{
    go(0, 0, 0, 0, 0);
    cout<<max_res<<"\n";
    cout<<min_res<<"\n"; 
}

int main()
{
    input();
    solve();
    return 0;
}
