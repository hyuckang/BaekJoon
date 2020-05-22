#include<iostream>
using namespace std;

int N, M;
int map[205][205], parent[205], route[205];

// find(x) : x의 root를 return
int my_find(int x)
{
    if(x == parent[x]) return x;
    else
    {
        int p = my_find(parent[x]);
        parent[x] = p;
        return p;
    }
}

// union(x, y) : x의 root를 y의 root로 하여 집합을 union한다.
void my_union(int x, int y)
{
    int x_parent = my_find(x);
    int y_parent = my_find(y);
    
    parent[y_parent] = x_parent;
}
void solve()
{
    // 초기화
    for(int i=1; i<=N; i++) parent[i] = i;

    // union
    for(int i=1; i<=N; i++)
    {
        for(int j=i; j<=N; j++)
        {
            if(map[i][j] == 1) my_union(i, j);
        }
    }

    // 경로가 같은 집합인지 확인
    int start_p = my_find(route[0]);
    for(int i=1; i<M; i++)
    {
        int route_p = my_find(route[i]);
        if(start_p != route_p)
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }

    for(int i=0; i<M; i++) cin>>route[i];
}
int main()
{
    input();
    solve();
    return 0;
}
