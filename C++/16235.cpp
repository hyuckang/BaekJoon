#include<iostream>
#include<queue>
using namespace std;

int N, M, K, base[15][15], A[15][15];
int dr[] = {-1, 1, 0, 0, -1, 1, -1, 1}, dc[] = {0, 0, -1, 1, -1, -1, 1 ,1};
deque<int> tree[15][15];
queue<int> dead_tree[15][15];

void winter()
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            base[i][j] += A[i][j];
}
void fall()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int tree_sz = tree[i][j].size();
            while(tree_sz--)
            {
                int T = tree[i][j].front();
                tree[i][j].pop_front();
                if(T % 5 == 0)
                {
                    for(int dir=0; dir<8; dir++)
                    {
                        int nr = i + dr[dir], nc = j + dc[dir];
                        if(nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
                        tree[nr][nc].push_front(1);
                    }
                }
                tree[i][j].push_back(T);
            }
        }
    }
}
void summer()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            while(!dead_tree[i][j].empty())
            {
                int T = dead_tree[i][j].front();
                dead_tree[i][j].pop();
                base[i][j] += T / 2;
            }
        }
    }
}
void spring()
{
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            int tree_sz = tree[i][j].size();
            while(tree_sz--)
            {
                int T = tree[i][j].front();
                tree[i][j].pop_front();
                if(T <= base[i][j])
                {
                    base[i][j] -= T;
                    T++;
                    tree[i][j].push_back(T);
                }
                else
                    dead_tree[i][j].push(T);
            }
        }
    }
}
void solve()
{
    while(K--)
    {
        spring();
        summer();
        fall();
        winter();
    }

    int res = 0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            res += tree[i][j].size();
        }
    }
    cout << res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin >> A[i][j];
            base[i][j] = 5;
        }
    }

    int x, y, z;
    for(int i=0; i<M; i++)
    {
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
}
int main()
{
    input();
    solve();
    return 0;
}
