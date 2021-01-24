#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, total_len, used_len;
int parent[105];
string LAN[105];

int my_find(int X)
{
    if(parent[X] == X)
        return X;
    else
    {
        parent[X] = my_find(parent[X]);
        return parent[X];
    }
}
void my_union(int X, int Y)
{
    // X의 부모를 Y의 부모로
    int p_X = my_find(X), p_Y = my_find(Y);
    if(p_X != p_Y)
        parent[p_Y] = p_X;
}
void solve()
{
    vector<tuple<int, int, int>> E;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(LAN[i][j] == '0') continue;
            
            int len;
            if('a' <= LAN[i][j] && LAN[i][j] <= 'z')
                len = LAN[i][j] - 'a' + 1;
            else if('A' <= LAN[i][j] && LAN[i][j] <= 'Z')
                len = LAN[i][j] - 'A' + 27;

            total_len += len;
            if(i != j)
                E.push_back({len, i + 1, j + 1});
        }
    }

    sort(E.begin(), E.end());

    int edge_cnt = 0;
    for(auto X : E)
    {
        int cost, i, j;
        tie(cost, i, j) = X;

        if(my_find(i) != my_find(j))
        {
            my_union(i, j);
            used_len += cost;
            edge_cnt++;
        }
    }

    if(edge_cnt == N - 1)
        cout << total_len - used_len;
    else
        cout << -1;    
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
        cin >> LAN[i];
}
void init()
{
    for(int i=0; i<105; i++)
        parent[i] = i;
}
int main()
{
    init();
    input();
    solve();
    return 0;
}
