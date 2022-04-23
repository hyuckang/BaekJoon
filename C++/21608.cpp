#include <iostream>
#include <set>
using namespace std;

int N, result;
int student[405], map[25][25];
set<int> S[405];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

int main()
{
    // input
    cin >> N;
    for(int i=0; i<N*N; i++)
    {
        cin >> student[i];
        for(int j=0; j<4; j++)
        {
            int like;
            cin >> like;
            S[student[i]].insert(like);
        }
    }

    // solve
    for(int i=0; i<N*N; i++)
    {
        int stu = student[i];
        int max_stu_cnt = -1, max_empty_cnt = -1;
        int R, C;

        for(int r=0; r<N; r++)
        {
            for(int c=0; c<N; c++)
            {
                // 학생이 그 자리에 앉을수 있다면
                if(map[r][c] == 0)
                {
                    // 인접한 학생 수, 비어 있는 칸 계산
                    int stu_cnt = 0, empty_cnt = 0;
                    for(int dir=0; dir<4; dir++)
                    {
                        int nr = r + dr[dir], nc = c + dc[dir];
                        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                        if (S[stu].find(map[nr][nc]) != S[stu].end())
                        {
                            stu_cnt++;
                        } 
                        if (map[nr][nc] == 0)
                        {
                            empty_cnt++;
                        }
                    }
                    
                    // 첫번째 조건
                    if (max_stu_cnt < stu_cnt)
                    {
                        max_stu_cnt = stu_cnt;
                        max_empty_cnt = empty_cnt;
                        R = r;
                        C = c;
                    }
                    // 두번째 조건
                    else if(max_stu_cnt == stu_cnt && max_empty_cnt < empty_cnt)
                    {
                        max_stu_cnt = stu_cnt;
                        max_empty_cnt = empty_cnt;
                        R = r;
                        C = c;
                    }
                    
                }
            }
        }
        // // 자리에 앉히기
        map[R][C] = stu;
    }
    
    // 만족도 점수 계산
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<N; c++)
        {
            int stu = map[r][c], stu_cnt = 0;
            for(int dir=0; dir<4; dir++)
            {
                int nr = r + dr[dir], nc = c + dc[dir];
                if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                if (S[stu].find(map[nr][nc]) != S[stu].end())
                {
                    stu_cnt++;
                }
            }
            if (stu_cnt == 1)
                result += 1;
            else if(stu_cnt == 2)
                result += 10;
            else if(stu_cnt == 3)
                result += 100;
            else if(stu_cnt == 4)
                result += 1000;
        }
    }
    
    cout << result;

    return 0;
}
