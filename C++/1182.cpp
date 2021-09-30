#include <iostream>
using namespace std;

int N, S, res = 0;
int A[25];

void go(int idx, int sum)
{
    if(idx == N)
    {
        if(sum == S)
        {
            res++;
        }
        return;
    }

    go(idx + 1, sum + A[idx]);
    go(idx + 1, sum);
}
int main()
{
    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> A[i];
    
    go(0, 0);
    
    // 합이 0일 경우, 공집합 제외
    if(S == 0)
        res--;
        
    cout << res;
}
