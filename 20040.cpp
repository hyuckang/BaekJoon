#include <iostream>
using namespace std;

int n, m, p[500005];

int my_find(int x)
{
    if(p[x] == x)
        return x;
    else
    {
        p[x] = my_find(p[x]);
        return p[x];
    }
}
void my_union(int x, int y)
{
    int x_p = my_find(x);
    int y_p = my_find(y);
    
    p[y_p] = x_p;
}
int main()
{
    // 어떤 두 노드의 부모노드가 같을 때 연결이 된다면, 사이클이 생긴다.

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++)
        p[i] = i;

    
    int turn = 0;
    for(int i=1; i<=m; i++)
    {
        int x, y;
        cin >> x >> y;

        if(my_find(x) == my_find(y))
        {
            turn = i;
            break;
        }
        else
            my_union(x, y);
    }

    cout << turn;

    return 0;
}
