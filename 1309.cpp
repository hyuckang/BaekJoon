#include<iostream>
using namespace std;

int N, D[100005][3];

void solve()
{
    // D[i][0] : i번째에 사자를 넣지 않았을때의 경우의 수
    // D[i][1] : i번째 왼쪽에 사자를 넣었을때의 경우의 수
    // D[i][2] : i번째 오른쪽에 사자를 넣었을때의 경우의 수
    D[1][0] = 1, D[1][1] = 1, D[1][2] = 1;
    for(int i=2; i<=N; i++)
    {
        D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % 9901;
        D[i][1] = (D[i - 1][0] + D[i - 1][2]) % 9901;
        D[i][2] = (D[i - 1][0] + D[i - 1][1]) % 9901;
    }

    int res = (D[N][0] + D[N][1] + D[N][2]) % 9901;
    cout<<res;
}
void input()
{
    cin>>N;
}
int main()
{
    input();
    solve();
    return 0;
}
