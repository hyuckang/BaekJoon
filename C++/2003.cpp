// two pointer
#include<iostream>
using namespace std;

int N, M;
int A[10005], res = 0;

void solve()
{
    // sum은 left와 right 구간의 합
    // sum = A[left] + ... + A[right]

    // sum < M : right를 늘리고, right가 지시하는 값을 더한다.
    // sum > M : left가 지시하는 값을 빼고, left를 늘린다.
    // sum == M : res를 하나 증가시키고, 무한루프에 빠지지 않기 위해 right를 하나 늘리고 값을 더해준다.
    int left = 1, right = 1, sum = A[left];
    while(true)
    {
        if(right > N) break;
        if(sum < M)
        {
            // right++;
            // sum += A[right];
            sum += A[++right];
        }
        else if(sum > M)
        {
            // sum -= A[left];
            // left++;
            sum -= A[left++];
        }
        else if(sum == M)
        {
            res++;
            // right++;
            // sum += A[right];
            sum += A[++right];
            continue;
        }

    }
    cout << res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> A[i];
}
int main()
{
    input();
    solve();
    return 0;
}
