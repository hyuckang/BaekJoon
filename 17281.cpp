/*
    1. 타순을 정하자 -> 순열
    1-1. 1번 선수는 무조건 "4번 타자"
    2. 타순을 정했다면 점수를 계산하자
*/
#include<iostream>
#include<vector>
using namespace std;

int N, max_res = -1;
int map[55][11];
bool select_[11];

int calc(vector<int> &nums)
{   
    int res = 0, out_cnt = 0, idx = 0;
    int ro_1 = 0, ro_2 = 0, ro_3 = 0, home = 0;
    for(int i=1; i<=N; i++)
    {
        // 이닝은 아웃 카운트가 3미만일 경우 계속 되기 때문에 무한 반복문
        while(true)
        {
            if(map[i][nums[idx]] == 0)
            {   // 아웃
                out_cnt++;
            }
            else if(map[i][nums[idx]] == 1)
            {   // 1루타
                home = ro_3;
                ro_3 = ro_2, ro_2 = ro_1, ro_1 = 1;
                res += home;
                home = 0;
            }
            else if(map[i][nums[idx]] == 2)
            {   // 2루타
                home = ro_3 + ro_2;
                ro_3 = ro_1, ro_2 = 1, ro_1 = 0;
                res += home;
                home = 0;
            }
            else if(map[i][nums[idx]] == 3)
            {   // 3루타
                home = ro_3 + ro_2 + ro_1;
                ro_3 = 1, ro_2 = 0, ro_1 = 0;
                res += home;
                home = 0;
            }
            else
            {   // 홈런
                home = ro_3 + ro_2 + ro_1 + 1;
                ro_3 = 0, ro_2 = 0, ro_1 = 0;
                res += home;
                home = 0;
            }
            
            // 타순 증가, idx는 벡터의 인덱스로 0부터 8까지
            idx++;
            if(idx == 9) idx = 0;
            
            // 아웃 카운트가 3이 되면 이닝 종료
            if(out_cnt == 3)
            {
                out_cnt = 0, ro_1 = 0, ro_2 = 0, ro_3 = 0;
                break;
            }
        }
    }
    return res;
}
void go(int idx, int cnt, vector<int> &nums)
{
    if(idx > 9) return;
    if(cnt == 9)
    {
        max_res = max(max_res, calc(nums));
        return;
    }
    
    if(idx == 3)
    {   // 4번째 타순의 선수는 무조건 1번
        select_[1] = true;
        nums.push_back(1);
        go(idx + 1, cnt + 1, nums);
        select_[1] = false;
        nums.pop_back();
    }

    // idx번째 타순의 선수 선택
    for(int i=2; i<10; i++)
    {   // 1번은 4번으로 고정되어 있기 때문에 2번부터 9번까지만 선택
        if(!select_[i])
        {
            select_[i] = true;
            nums.push_back(i);
            go(idx + 1, cnt + 1, nums);
            select_[i] = false;
            nums.pop_back();
        }
    }

    // idx번째 타순의 선수 선택하지 않음
    go(idx + 1, cnt, nums);
}
void solve()
{
    vector<int> nums;
    go(0, 0, nums);
    cout<<max_res;
}
void input()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<10; j++)
        {
            cin>>map[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
