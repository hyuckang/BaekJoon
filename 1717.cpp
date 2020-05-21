#include<iostream>
using namespace std;

int N, M;
int parent[1000005];    // parent[a] : a의 root를 저장

// find(x) : 원소 x의 root를 반환
int my_find(int x)
{
    // x가 root라면 return x
    if(parent[x] == x) return x;
    else
    {
        // 경로 압축 (path compression)
        int p = my_find(parent[x]);
        parent[x] = p;
        return p;
    }
}

// union(x, y) : x의 root가 y의 root가 되도록 집합을 합친다. 
void my_union(int x, int y)
{
    int x_parent = my_find(x);
    int y_parent = my_find(y);

    parent[y_parent] = x_parent;
}

void solve()
{
    // 초기화
    for(int i=0; i<=N; i++) parent[i] = i;

    int oper, a, b;
    for(int i=0; i<M; i++)
    {
        cin>>oper>>a>>b;
        if(oper == 0)
        {
            my_union(a, b);
        }
        else
        {
            if(my_find(a) == my_find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;
}
int main()
{
    input();
    solve();
    return 0;
}
