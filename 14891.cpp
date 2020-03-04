#include<iostream>
#include<string>
using namespace std;
string wheel[5];
int K;
void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=1; i<=4; i++)
    {
        cout<<wheel[i]<<"\n";
    }
    cout<<"===========\n";
}
int check_rotation(int wheel_1, int wheel_2, int wheel_1_dir)
{
    // wheel_1로 인해서 wheel_2가 돌아가야하는지 검사
    // 돌아가야 한다면 wheel_1_dir * -1를 반환
    // 돌아가지 않아도 된다면 0을 반환
    int wheel_1_cmp, wheel_2_cmp;
    if(wheel_1 < wheel_2) // (1,2) (2,3) (3,4)
    {   
        wheel_1_cmp = 2;
        wheel_2_cmp = 6;
    }
    else// wheel_1 > wheel_2, (4,3) (3,2) (2,1)
    {   
        wheel_1_cmp = 6;
        wheel_2_cmp = 2;
    }
    if(wheel[wheel_1][wheel_1_cmp] != wheel[wheel_2][wheel_2_cmp])
    {   // wheel_2가 회전해야함
        return wheel_1_dir * -1;
    }
    else
    {   // wheel_2가 회전하지 않아도 됨
        return 0;
    }
    
}
void rotation(int wheel_num, int dir)
{
    if(dir == 1)
    {   // 시계 회전
        char tmp = wheel[wheel_num][7];
        for(int i=6; i>=0; i--)
        {
            wheel[wheel_num][i+1] = wheel[wheel_num][i];
        }
        wheel[wheel_num][0] = tmp;
    }
    else if(dir == -1)// dir == -1
    {   // 반시계 회전
        char tmp = wheel[wheel_num][0];
        for(int i=1; i<=7; i++)
        {
            wheel[wheel_num][i-1] = wheel[wheel_num][i];
        }
        wheel[wheel_num][7] = tmp;
    }
}
void input()
{
    for(int i=1; i<=4; i++)
    {
        cin>>wheel[i];
    }
    cin>>K;
}
void solve()
{
    while(K--)
    {
        int num, dir;
        cin>>num>>dir;
        rotation(num, dir);
        
        if(num == 1)
        {   // 1->2->3->4
            int res_2 = check_rotation(1, 2, dir);
            if(res_2 != 0)
            {
                rotation(2, res_2);
                int res_3 = check_rotation(2, 3, res_2);
                if(res_3 != 0)
                {
                    rotation(3, res_3);
                    int res_4 = check_rotation(3, 4, res_3);
                    if(res_4 != 0)
                    {
                        rotation(4, res_4);
                    }
                }
            }
        }
        else if (num == 2)
        {   // 2->1
            int res_1 = check_rotation(2, 1, dir);
            if(res_1 != 0)
            {
                rotation(1, res_1);
            }
            // 2->3->4
            int res_3 = check_rotation(2, 3, dir);
            if(res_3 != 0)
            {
                rotation(3, res_3);
                int res_4 = check_rotation(3, 4, res_3);
                if(res_4 != 0)
                {
                    rotation(4, res_4);
                }
            }
        }
        else if(num == 3)
        {
            // 3->2->1
            int res_2 = check_rotation(3, 2, dir);
            if(res_2 != 0)
            {
                rotation(2, res_2);
                int res_1 = check_rotation(2, 1, res_2);
                if(res_1 != 0)
                {
                    rotation(1, res_1);
                }
            }
            // 3->4
            int res_4 = check_rotation(3, 4, dir);
            if(res_4 != 0)
            {
                rotation(4, res_4);
            }
        }
        else if(num == 4) 
        {
            // 4->3->2->1
            int res_3 = check_rotation(4, 3, dir);
            if(res_3 != 0)
            {
                rotation(3, res_3);
                int res_2 = check_rotation(3, 2, res_3);
                if(res_2 != 0)
                {
                    rotation(2, res_2);
                    int res_1 = check_rotation(2, 1, res_2);
                    if(res_1 != 0)
                    {
                        rotation(1, res_1);
                    }
                }
            }
        }
    }
    
    // 점수 계산
    int res = 0;
    if(wheel[1][0] == '1')
    {
        res = res + 1;
    }
    if(wheel[2][0] == '1')
    {
        res = res + 2;
    }
    if(wheel[3][0] == '1')
    {
        res = res + 4;
    }
    if(wheel[4][0] == '1')
    {
        res = res + 8;
    }
    cout<<res<<"\n";
    
}
int main()
{
    input();
    solve();
    pr_map();
    return 0;
}
