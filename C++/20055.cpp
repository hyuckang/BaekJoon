#include <iostream>
using namespace std;

int N, K, result = 0;
int A[205], R[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    for (int i=1; i<=2*N; i++)
        cin >> A[i];

    while (true)
    {
        result++;

        // [1] 벨트 이동
        int tmp_A = A[2 * N];
        for (int i=2*N; i>1; i--)
            A[i] = A[i - 1];
        A[1] = tmp_A;

        // [1] 벨트에 있는 로봇 이동
        for (int i=N; i>1; i--)
        {
            R[i] = R[i - 1];            
        }
        R[N] = 0, R[1] = 0;

        // [2] 로봇 스스로 이동
        for (int i=N; i>0; i--)
        {
            // 로봇이 있고, 이동하려는 칸에 로봇이 없고, 내구도가 1이상
            if (R[i - 1] == 1 && R[i] == 0 && A[i] > 0)
            {
                R[i] = R[i - 1];
                R[i - 1] = 0;
                A[i]--;
            }
        }
        R[N] = 0;

        // [3]
        if (A[1] > 0)
            R[1] = 1, A[1]--;

        // [4] 내구도가 0인 칸이 K개 이상이면 종료
        int count = 0;
        for (int i=1; i<=2*N; i++)
        {
            if (A[i] == 0) count++;
        }
        if (K <= count) break;
    }

    cout << result << "\n";

    return 0;
}
