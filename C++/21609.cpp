#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, map[25][25], vist[25][25];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int result = 0;

void rotate()
{
    int tmp_map[25][25];

    for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            tmp_map[r][c] = map[c][N - r - 1];
            
    for (int r=0; r<N; r++)
        for (int c=0; c<N; c++)
            map[r][c] = tmp_map[r][c];
}
void gravity()
{
    for (int c=0; c<N; c++)
    {
        int r = N - 1;
        while (r > 0)
        {
            if (map[r][c] == -2)
            {
                if (map[r - 1][c] == -1 || map[r - 1][c] == -2)
                    r--;
                else if(map[r - 1][c] >= 0)
                {
                    swap(map[r][c], map[r - 1][c]);
                    r += 2;
                }
            }
            else
                r--;
        }
    }
}
int main()
{
    // input
    cin >> N >> M;
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            cin >> map[i][j];

    // solve
    // [1] 크기가 가장 큰 블록그룹 찾기
    while (true)
    {
        vector<pair<int, int>> max_rainbow;
        vector<pair<int, int>> max_normal;
        
        for (int r=0; r<N; r++)
        {
            for (int c=0; c<N; c++)
            {
                vector<pair<int, int>> rainbow;
                vector<pair<int, int>> normal;
                
                // 일반 블럭이면
                if (0 < map[r][c])
                {
                    memset(vist, 0, sizeof(vist));
                    
                    queue<pair<int, int>> Q;
                    Q.push({r, c});
                    vist[r][c] = 1;

                    normal.push_back({r, c});

                    while (!Q.empty())
                    {
                        pair<int, int> cur = Q.front(); Q.pop();
                        for (int dir=0; dir<4; dir++)
                        {
                            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
                            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                            if (map[nr][nc] == -1 || vist[nr][nc] == 1) continue;
                            if (map[nr][nc] == 0 || map[r][c] == map[nr][nc])
                            {
                                Q.push({nr, nc});
                                vist[nr][nc] = 1;

                                if(map[nr][nc] == 0)
                                    rainbow.push_back({nr, nc});
                                else
                                    normal.push_back({nr, nc});
                            }
                        }
                    }
                }

                sort(normal.begin(), normal.end());  // 기준 블럭 찾기위한 정렬

                int max_block_sz = max_rainbow.size() + max_normal.size();
                int max_rainbow_sz = max_rainbow.size();
                int block_sz = rainbow.size() + normal.size();
                int rainbow_sz = rainbow.size();

                if (block_sz < 2) continue;

                if (max_block_sz < block_sz)
                {
                    max_rainbow = rainbow;
                    max_normal = normal;
                }
                else if (max_block_sz == block_sz && max_rainbow_sz < rainbow_sz)
                {
                    max_rainbow = rainbow;
                    max_normal = normal;
                }
                else if(max_normal.empty() == false && normal.empty() == false)
                {
                    // 기준 블럭 행으로 비교
                    if (
                        max_block_sz == block_sz && max_rainbow_sz == rainbow_sz &&
                        max_normal[0].first < normal[0].first)
                    {
                        max_rainbow = rainbow;
                        max_normal = normal;
                    }
                    // 기준 블럭 열로 비교
                    else if (max_block_sz == block_sz && max_rainbow_sz == rainbow_sz &&
                    max_normal[0].first == normal[0].first && max_normal[0].second < normal[0].second)
                    {
                        max_rainbow = rainbow;
                        max_normal = normal;
                    }
                }
            }
        }

        if(max_normal.empty()) break;

        // [2]. 블록 그룹의 모든 블록 제거, 점수 카운트
        for(auto block : max_rainbow)
            map[block.first][block.second] = -2;
        for(auto block : max_normal)
            map[block.first][block.second] = -2;

        int max_block_sz = max_rainbow.size() + max_normal.size();
        result += (max_block_sz * max_block_sz);

        // [3]. 격자의 중력
        gravity();

        // [4]. 격자를 반시계로 90 회전
        rotate();

        // [5]. 격자에 중력
        gravity();
    }


    cout << result << "\n";

    return 0;
}
