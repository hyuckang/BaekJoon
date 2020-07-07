#include<iostream>
using namespace std;

long long N, x, y;
int K, Q;

void solve()
{
    while(Q--)
    {
        cin >> x >> y;
        long long res = 0;
        if(K == 1)
            res = abs(x - y);
        else
        {   
            // K진 트리에서 i번째 노드의 부모노드 : (i - 2)/K + 1
            // 같은 부모가 나올 때 까지높이가 더 낮은 노드를 부모 노드로 올린다.
            while(x != y)
            {
                if(x > y)
                {
                    x = (x - 2)/K + 1;
                }
                else // x > y
                {
                    y = (y - 2)/K + 1;
                }
                res++;
            }
        }
        cout << res << "\n";
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K >> Q;
}
int main()
{
    input();
    solve();
    return 0;
}
