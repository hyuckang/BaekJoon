#include <iostream>
using namespace std;

int N, res = 0;
bool col[20], A[30], B[30];

// row행에 Queen을 둘 차례
void go(int row)
{
    if(row >= N)
    {
        res++;
        return;
    }

    for(int i=0; i<N; i++)
    {
        // A : 왼쪽 대각선, B : 오른쪽 대각선
        if(col[i] == false && A[row + i] == false && B[row - i + (N - 1)] == false)
        {
            col[i] = true, A[row + i] = true, B[row - i + (N - 1)] = true;
            go(row + 1);
            col[i] = false, A[row + i] = false, B[row - i + (N - 1)] = false;
        }
    }
}

int main()
{
    cin >> N;
    go(0);
    cout << res;
    return 0;
}
