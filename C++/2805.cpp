#include <iostream>
#include <algorithm>
using namespace std;

int N, M, max_tree = -1;
int A[1000005];

void solve()
{
    // 0 ~ max_tree : 나무 중 최대 값에서 이분 탐색    
    long long st = 0, en = max_tree;
    int answer;

    while(st <= en)
    {
        long long mid = (st + en) / 2;
        
        // 나무 자르기
        long long cut_res = 0;
        for(int i=0; i<N; i++)
        {
            long long cut = A[i] - mid;
            if(cut > 0) cut_res += cut;
        }

        if(cut_res >= M) // M을 넘었으니 기록하고 게속 탐색
        {
            answer = mid;
            st = mid + 1;
        }
        else // cut_res < M : 더 잘라야하기에 높이를 올린다
        {
            en = mid - 1;
        }
    }

    cout << answer;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
        max_tree = max(max_tree, A[i]);    
    }
}
int main()
{
    input();
    solve();
    return 0;
}
