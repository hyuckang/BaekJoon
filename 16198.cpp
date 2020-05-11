#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N, max_res = -987654321;
int A[15], B[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
bool is_delete[15];

int calc_energy(int idx)
{
    // A에서 idx 번째를 삭제했을 때의 에너지 계산
    int left, right;
    for(int i = idx + 1; i < N; i++)
    {
        if(!is_delete[i])
        {
            right = i;
            break;
        }
    }
    for(int i = idx - 1; i >= 0; i--)
    {
        if(!is_delete[i])
        {
            left = i;
            break;
        }
    }
    return A[left] * A[right];
}
void solve()
{
    do
    {
        memset(is_delete, false, sizeof(is_delete));
        int res = 0;
        for(int i=0; i<(N-2); i++)
        {
            is_delete[B[i]] = true;
            res += calc_energy(B[i]);
        }
        max_res = max(max_res, res);
    } while (next_permutation(B, B + N - 2));
    
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
