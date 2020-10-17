#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int V, E;
int p[10005];
vector<tuple<int, int, int>> Edge;

int my_find(int x)
{
    // x의 부모를 return
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
    // x의 부모를 y의 부모로
    int x_p = my_find(x), y_p = my_find(y);
    if(x_p != y_p)
    {
        p[y_p] = x_p;
    }
}
void solve()
{
    for(int i=1; i<=V; i++)
        p[i] = i;
    
    sort(Edge.begin(), Edge.end());
    
    long long int res = 0;
    int Edge_cnt = 0;
    for(int i=0; i<E; i++)
    {
        // if(Edge_cnt == E - 1) break;

        long long cost;
        int A, B;
        tie(cost, A, B) = Edge[i];

        // i번째 선택
        if(my_find(A) != my_find(B))
        {
            my_union(A, B);
            res += cost;
            Edge_cnt++;
        }
    }
    cout << res;
}
void input()
{
    cin >> V >> E;
    for(int i=0; i<E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Edge.push_back(make_tuple(C, A, B));
    }
}
int main()
{
    input();
    solve();
    return 0;
}
