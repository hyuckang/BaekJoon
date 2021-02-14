#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, T;
int MAP[105][105], vist[105][105];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int main()
{
    // input
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> T;
    for(int r=0; r<N; r++)
        for(int c=0; c<M; c++)
            cin >> MAP[r][c];


    // solve
    pair<int, int> gram = {-1, -1};
    
    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vist[0][0] = 0;
    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();

        if(MAP[cur.first][cur.second] == 2) gram = cur;
            
        for(int dir=0; dir<4; dir++)
        {
            pair<int, int> next = {cur.first + dr[dir], cur.second + dc[dir]};
            if(next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
            if(vist[next.first][next.second] >= 0 || MAP[next.first][next.second] == 1) continue;
            Q.push(next);
            vist[next.first][next.second] = vist[cur.first][cur.second] + 1;
        }
    }

    int answer, gram_road = vist[gram.first][gram.second] + abs((N - 1) - gram.first) + abs((M - 1) - gram.second);
    if(vist[N - 1][M - 1] == -1)
    {
        if(gram.first == -1 && gram.second == -1)
            answer = -1;
        else
            answer = gram_road;
    }
    else
        answer = min(vist[N - 1][M - 1], gram_road);

    if(answer != -1 && answer <= T)
        cout << answer;
    else
        cout << "Fail";

    return 0;
}
