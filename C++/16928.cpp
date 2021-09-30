/*
    !!
    사다리와 뱀의 시작과 끝은 한 칸으로 이어져있음
    !!
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
// map : 0이라면 빈칸, 0이 아니라면 사다리와 뱀의 끝점을 의미
int map[105], vist[105];

void solve()
{
    memset(vist, -1, sizeof(vist));

    queue<int> Q;
    Q.push(1);
    vist[1] = 0;

    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        if(cur == 100)
        {
            cout << vist[100];
            return;
        }

        for(int dice=1; dice<7; dice++)
        {
            int next = cur + dice;
            if(next > 100) continue;
            // 빈칸이 아니고, 사다리나 뱀이라면 next가 사다리나 뱀의 끝점으로 바뀜
            if(map[next] > 0)
                next = map[next];

            // next를 방문하지 않았다면, 방문
            if(vist[next] == -1)
            {
                Q.push(next);
                vist[next] = vist[cur] + 1;
            }
        }
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        int x, y;
        cin >> x >> y;
        map[x] = y;
    }
    for(int i=0; i<M; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }
}
int main()
{
    input();
    solve();
    return 0;
}
