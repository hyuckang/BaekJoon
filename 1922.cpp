#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int N, M;
// {cost, v1, v2}
tuple<int, int, int> edge[100005];
int parent[100005];

// find(x) : 원소 x의 root를 반환
int my_find(int x)
{
    if(parent[x] == x) return x;
    else
    {
        int p = my_find(parent[x]);
        parent[x] = p;
        return p;    
    }
}
// union(x, y) : x의 root가 y의 루트가 되도록 집합을 합친다.
void my_union(int x, int y)
{
    int x_parent = my_find(x);
    int y_parent = my_find(y);
    parent[y_parent] = x_parent;
}

void solve()
{
    // parent 초기화
    for(int i=0; i<N; i++) parent[i] = i;

    // cost를 기준으로 정렬
    sort(edge, edge + M);
    
    // 크루스칼 알고리즘
    int cost_sum = 0;
    for(int i=0; i<M; i++)
    {
        int cost, v1, v2;
        tie(cost, v1, v2) = edge[i];

        // 같은 그룹이 아니라면 union 하고, 비용을 더한다    
        if(my_find(v1) != my_find(v2))
        {
            my_union(v1, v2);
            cost_sum += cost;
        }
    }
    
    cout << cost_sum;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int a, b, c;
    for(int i=0; i<M; i++)
    {
        cin >> a >> b >> c;
        edge[i] = tie(c, a, b);
    }
}
int main()
{
    input();
    solve();
    return 0;
}
