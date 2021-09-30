#include <iostream>
using namespace std;

int N, ranking[55];
pair<int, int> A[55];

void solve()
{
    for(int i=0; i<N; i++)
    {
        int cnt = 0;
        for(int j=0; j<N; j++)
        {
            if(i == j) continue;
            if(A[i].first < A[j].first && A[i].second < A[j].second)
                cnt++;
        }
        ranking[i] = cnt + 1;
    }

    for(int i=0; i<N; i++)
        cout << ranking[i] << " ";
}
void input()
{
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i].first >> A[i].second;
}
int main()
{
    input();
    solve();
    return 0;
}
