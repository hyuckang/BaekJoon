#include <iostream>
#include <vector>
using namespace std;

string board[9];
vector<pair<int, int>> empty;
int empty_cnt;

bool check_col(int r, int c, int val)
{
    val = val + '0';
    for(int i=0; i<9; i++)
    {
        if(board[i][c] == val) return false;
    }
    return true;
}
bool check_row(int r, int c, int val)
{
    val = val + '0';
    for(int i=0; i<9; i++)
    {
        if(board[r][i] == val) return false;
    }
    return true;
}
bool check_box(int r, int c, int val)
{
    r = (r / 3) * 3, c = (c / 3) * 3;
    val = val + '0';
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[r + i][c + j] == val) return false;
        }
    }
    return true;
}
void go(int idx)
{
    if(idx == empty_cnt)
    {
        for(int i=0; i<9; i++)
            cout << board[i] << "\n";

        exit(0);
    }

    int r = empty[idx].first, c = empty[idx].second;   
    for(int i=1; i<=9; i++)
    {
        if(check_row(r, c, i) && check_col(r, c, i) && check_box(r, c, i))
        {
            board[r][c] = i + '0';
            go(idx + 1);
            board[r][c] = '0';
        }
    }
}
int main()
{
    for(int i=0; i<9; i++)
        cin >> board[i];

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(board[i][j] == '0')
            {
                empty.push_back({i, j});
            }
        }
    }

    empty_cnt = empty.size();
    go(0);

    return 0;
}
