#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, Q, X = 1, result = 0, max_ice = -1;
int A[70][70], L[1005];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

void rotate(int r, int c, int size)
{
    int tmp_A[70][70] = {0, };

    for (int x=0; x<size; x++)
        for (int y=0; y<size; y++)
            tmp_A[y + r][size - x - 1 + c] = A[x + r][y + c];

    for (int x=0; x<size; x++)
        for (int y=0; y<size; y++)
            A[x + r][y + c] = tmp_A[x + r][y + c];
}
int main()
{
    cin >> N >> Q;
    X = (1 << N);

    for (int r=0; r<X; r++)
        for (int c=0; c<X; c++)
            cin >> A[r][c];

    for (int i=0; i<Q; i++)
        cin >> L[i];

    for (int q=0; q<Q; q++)
    {
        // 90도 회전
        int size = (1 << L[q]);
        for (int r=0; r<X; r+=size)
            for (int c=0; c<X; c+=size)
                rotate(r, c, size);

        // 얼음 녹이기
        vector<pair<int, int>> melt;
        for (int r=0; r<X; r++)
        {
            for (int c=0; c<X; c++)
            {
                if (A[r][c] > 0)
                {
                    int count = 0;
                    for (int dir=0; dir<4; dir++)
                    {
                        int nr = r + dr[dir], nc = c + dc[dir];
                        if (nr < 0 || nr >= X || nc < 0 || nc >= X) continue;
                        if (A[nr][nc] > 0) count++;
                    }

                    if (count < 3) melt.push_back({r, c});
                }
            }
        }

        for (auto it : melt)
            A[it.first][it.second]--;
    }

    bool vist[70][70] = {false, };
    for (int r=0; r<X; r++)
    {
        for (int c=0; c<X; c++)
        {
            result += A[r][c];
            if (!vist[r][c] && A[r][c] > 0)
            {
                int count = 1;
                queue<pair<int, int>> Q;
                vist[r][c] = true;
                Q.push({r, c});

                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for (int dir=0; dir<4; dir++)
                    {
                        int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
                        if (nr < 0 || nr >= X || nc < 0 || nc >= X) continue;
                        if (vist[nr][nc] || A[nr][nc] == 0) continue;

                        vist[nr][nc] = true;
                        Q.push({nr, nc});
                        count++;
                    }
                }

                max_ice = max(max_ice, count);
            }
        }
    }
        
    cout << result << "\n";
    if (max_ice == -1)
        max_ice = 0;
    cout << max_ice << "\n";

    return 0;
}
