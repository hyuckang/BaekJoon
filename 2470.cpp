#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, A[100005];
    
    // 입력
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];

    // 정렬 : O(N * log N)
    sort(A, A + N);

    // 투 포인터, O(N)
    int st = 0, en = N - 1;
    int min_val = A[st] + A[en], left = st, right = en;
    
    while(st < en)
    {
        if(abs(0 - min_val) > abs(0 - (A[st] + A[en])))
        {
            min_val = A[st] + A[en];
            left = st, right = en;
        }

        if(A[st] + A[en] == 0)
        {
            left = st, right = en;
            break;
        }
        else if(A[st] + A[en] < 0)
            st++;
        else // A[st] + A[en] > 0
            en--;
    }
    
    cout << A[left] << " " << A[right];

    return 0;
}
