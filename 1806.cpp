// two pointer
#include<iostream>
using namespace std;
int N, S, A[100100], min_res = 987654321;

void solve()
{
    int left = 0, right = 0, sum = A[left];
    while(true)
    {
        if(right >= N) break;

        if(sum < S)
            sum += A[++right];
        else // sum >= S
        {
            min_res = min(min_res, right - left + 1);
            sum -= A[left++];
        }
    }

    if(min_res == 987654321)
        cout << 0;
    else
        cout << min_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> A[i];
}
int main()
{
    input();
    solve();
    return 0;
}
