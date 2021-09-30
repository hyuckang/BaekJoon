/*
    최소 스패닝 트리
    크루스칼 알고리즘, 유니온 파인드
*/
#include<iostream>
#include<tuple>
#include<algorithm>
#include<cmath>
using namespace std;

int n, parent[105];
pair<double, double> stars[105];
// <cost, v1, v2>
tuple<double, int, int> edge[5000];

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
void my_union(int x, int y)
{
    int x_parent = my_find(x);
    int y_parent = my_find(y);
    parent[y_parent] = x_parent;
}
double dist(pair<double, double> v1, pair<double, double> v2)
{
    double x = abs(v1.first - v2.first) * abs(v1.first - v2.first);
    double y = abs(v1.second - v2.second) * abs(v1.second - v2.second);
    return sqrt(x+y);
}
void solve()
{
    // parent 초기화
    for(int i=0; i<n; i++) parent[i] = i;

    // 간선 비용 구하기
    int edge_sz = 0;
    for(int v1=0; v1<n-1; v1++)
    {
        for(int v2=v1+1; v2<n; v2++)
        {
            double cost = dist(stars[v1], stars[v2]);
            edge[edge_sz++] = tie(cost, v1, v2);
        }
    }

    // cost를 기준으로 정렬
    sort(edge, edge + edge_sz);

    // 크루스칼 알고리즘
    double cost_sum = 0;
    for(int i=0; i<edge_sz; i++)
    {
        double cost;
        int v1, v2;
        tie(cost, v1, v2) = edge[i];
        
        if(my_find(v1) != my_find(v2))
        {
            my_union(v1, v2);
            cost_sum += cost;
        }
    }

    // 출력 자릿수를 3자릿수로 조절
    cout.precision(3);
    cout<< cost_sum;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> stars[i].first >> stars[i].second;
}
int main()
{
    input();
    solve();
    return 0;
}
