// 힙
// 최소 힙 -> 루트는 최솟 값이고, 부모는 자식보다 "작아야한다."
// 최대 힙 -> 루트는 최댓 값이고, 부모는 자식보다 "커야한다.
// 힙은 원소의 삽입, 최대(혹은 최소)값 확인, 최대(혹은 최소)값 삭제가 가능
// 최소 혹은 최대가 아닌 값의 존재 여부와 삭제가 불가능

#include<iostream>
#include<queue>
using namespace std;

int N;
// 우선 순위 큐를 이용한 최소힙
priority_queue<int, vector<int>, greater<int>> PQ;
// 기본 우선 순위 큐 => 최대힙
// priority_queue<int> PQ;


void solve()
{
    int X;
    for(int i=0; i<N; i++)
    {
        cin >> X;
        if(X == 0)
        {
            if(PQ.empty()) cout << 0 << "\n";
            else
            {
                cout << PQ.top() << "\n";
                PQ.pop();
            }
        }
        else PQ.push(X);
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >>N;
}
int main()
{
    input();
    solve();
    return 0;
}
