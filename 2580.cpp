#include<iostream>
#include<vector>
using namespace std;

int map[10][10], empty_sz;
bool end_flag = false;
vector<pair<int, int>> empty;
void pr_map()
{
    for(int r=0; r<9; r++)
    {
        for(int c=0; c<9; c++)
        {
            cout<<map[r][c]<<" ";
        }
        cout<<"\n";
    }
}
bool check_box(int r, int c, int val)
{
    int box_r = (r / 3) * 3, box_c = (c / 3) * 3;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(map[box_r + i][box_c + j] == val) return false;
        }
    }
    return true;
}
bool check_column(int r, int c, int val)
{
    for(int i=0; i<9; i++)
    {
        if(map[i][c] == val) return false;
    }
    return true;
}
bool check_row(int r, int c, int val)
{
    for(int i=0; i<9; i++)
    {   
        if(map[r][i] == val) return false;
    }
    return true;
}
void go(int idx)
{
    // idx 번째 숫자 정하기
    int cur_r = empty[idx].first, cur_c = empty[idx].second;

    // 모든 빈칸 채웠으면
    if(idx == empty_sz && end_flag == false)
    {
        end_flag = true;
        pr_map();
        return;
    }

    for(int i=1; i<10; i++)
    {
        if(check_row(cur_r, cur_c, i) && check_column(cur_r, cur_c, i) && check_box(cur_r, cur_c, i))
        {
            map[cur_r][cur_c] = i;
            go(idx + 1);
            if(end_flag) return;
            map[cur_r][cur_c] = 0;
        }
    }
}
void solve()
{
    empty_sz = empty.size();
    go(0);
    return;
}
void input()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 0) empty.push_back(make_pair(i, j));
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
