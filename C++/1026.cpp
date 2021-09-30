#include <iostream>
#include <algorithm>
using namespace std;

int N, A[55], B[55], res = 0;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<N; i++)
        cin >> B[i];

    sort(A, A + N);
    sort(B, B + N);

    for(int i=0; i<N; i++)
        res += (A[i] * B[N - i - 1]);
    
    cout << res;
    return 0;
}
