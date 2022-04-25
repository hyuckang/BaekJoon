#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, K, score;
int map[25][25];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

int bfs(int r, int c)
{
    int count = 0;
    bool vist[25][25];
    memset(vist, false, sizeof(vist));

    queue<pair<int, int>> Q;
    Q.push({r, c});
    vist[r][c] = true;
    count++;

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for (int d=0; d<4; d++)
        {
            int nr = cur.first + dr[d], nc = cur.second + dc[d];
            if (nr <= 0 || nr > N || nc <= 0 || nc > M) continue;
            if (vist[nr][nc] || map[r][c] != map[nr][nc]) continue;
            
            Q.push({nr, nc});
            vist[nr][nc] = true;
            count++;
        }
    }

    return count;
}
int clock_90(int d)
{
    return (d + 1) % 4;
}
int change_dir(int d)
{
    if (d == 0) return 2;
    else if (d == 1) return 3;
    else if (d == 2) return 0;
    else return 1;
}
int main()
{
    cin >> N >> M >>K;
    for (int r=1; r<=N; r++)
        for (int c=1; c<=M; c++)
            cin >> map[r][c];

    int r = 1, c = 1, dir = 0;
    int Top = 1, Bottom = 6;
    int Right = 3, Left = 4, North = 2, South = 5;

    while (K--)
    {
        // [1]
        int nr = r + dr[dir], nc = c + dc[dir];
        if (nr <= 0 || nr > N || nc <= 0 || nc > M)
        {
            dir = change_dir(dir);
            nr = r + dr[dir], nc = c + dc[dir];
        }
        
        r = nr, c = nc;
        
        if (dir == 0)
        {
            swap(Bottom, Right);
            swap(Right, Top);
            swap(Top, Left);
        }
        else if (dir == 1)
        {
            swap(Bottom, South);
            swap(South, Top);
            swap(Top, North);
        }
        else if (dir == 2)
        {
            swap(Bottom, Left);
            swap(Left, Top);
            swap(Top, Right);
        }
        else if (dir == 3)
        {
            swap(Bottom, North);
            swap(North, Top);
            swap(Top, South);
        }
        
        // [2]
        int B = map[nr][nc], C = bfs(nr, nc);
        score += B * C;

        // [3]
        if (Bottom > B)
            dir = clock_90(dir);
        else if (Bottom < B)
        {
            dir = clock_90(dir);
            dir = clock_90(dir);
            dir = clock_90(dir);
        }
    }
    
    cout << score;

    return 0;
}
