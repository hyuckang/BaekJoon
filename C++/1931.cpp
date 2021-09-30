#include <iostream>
#include <algorithm>
using namespace std;

int N, start_time, end_time, res = 1;
pair<int, int> A[100005]; // {종료시간, 시작시간}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i].second >> A[i].first;

    sort(A, A + N);

    start_time = A[0].second, end_time = A[0].first;
    for(int i=1; i<N; i++)
    {
        if(end_time <= A[i].second)
        {
            start_time = A[i].second, end_time = A[i].first;
            res++;
        }
    }

    cout << res;
    return 0;
}
