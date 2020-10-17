#include <iostream>
#include <vector>
using namespace std;

int N, white_res = -987654321, black_res = -987654321;
int map[15][15], A[20], B[20];
vector<pair<int, int>> white_pos;
vector<pair<int, int>> black_pos;

void white_go(int idx, int cnt)
{
    if(idx == white_pos.size())
    {
        white_res = max(white_res, cnt);
        return;
    }

    int idx_r = white_pos[idx].first, idx_c = white_pos[idx].second;
    if(A[idx_r + idx_c] == false && B[idx_r - idx_c + (N - 1)] == false)
    {
        A[idx_r + idx_c] = true, B[idx_r - idx_c + (N - 1)] = true;
        white_go(idx + 1, cnt + 1);
        A[idx_r + idx_c] = false, B[idx_r - idx_c + (N - 1)] = false;
    }
    
    white_go(idx + 1, cnt);
}
void black_go(int idx, int cnt)
{
    if(idx == black_pos.size())
    {
        black_res = max(black_res, cnt);
        return;
    }

    // idx번째 놓기
    int idx_r = black_pos[idx].first, idx_c = black_pos[idx].second;
    // A : 왼쪽 대각선, B : 오른쪽 대각선
    if(A[idx_r + idx_c] == false && B[idx_r - idx_c + (N - 1)] == false)
    {
        A[idx_r + idx_c] = true, B[idx_r - idx_c + (N - 1)] = true;
        black_go(idx + 1, cnt + 1);
        A[idx_r + idx_c] = false, B[idx_r - idx_c + (N - 1)] = false;
    }

    // idx번째 놓지 않기
    black_go(idx + 1, cnt);
}
void solve()
{
    black_go(0, 0);
    white_go(0, 0);
    cout << black_res + white_res;
}
void input()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 1)
            {
                if(i % 2 == 0)
                {
                    if(j % 2 == 0)
                        black_pos.push_back(make_pair(i, j));
                    else
                        white_pos.push_back(make_pair(i, j));
                }
                else
                {
                    if(j % 2 == 1)
                        black_pos.push_back(make_pair(i, j));
                    else
                        white_pos.push_back(make_pair(i, j));
                }
            }
            
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
