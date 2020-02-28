#include<iostream>
#include<string>

using namespace std;

string wheel[5];
int K;
int rot[2][100], wheel_12[5];
int wheel_right[5] = {-1, 2, 2, 2, 2};
int wheel_left[5] = {-1, 6, 6, 6, 6};

void rotation(int wheel_num, int dir)
{
    // 바퀴 번호와 방향을 받아 바퀴를 회전시켜준다.
    if(dir == 1)
    {
        // 시계 회전
        if(wheel_12[wheel_num] == 0)
        {
            wheel_12[wheel_num] = 7;
        }
        else
        {
            wheel_12[wheel_num]--;
        }

        if(wheel_left[wheel_num] == 0)
        {
            wheel_left[wheel_num] = 7;
        }
        else
        {
            wheel_left[wheel_num]--;
        }
        
        if(wheel_right[wheel_num] == 0)
        {
            wheel_right[wheel_num] = 7;
        }
        else
        {
            wheel_right[wheel_num]--;
        }
    }
    else if(dir == -1)
    {
        // 반시계 회전
        if(wheel_12[wheel_num] == 7)
        {
            wheel_12[wheel_num] == 0;
        }
        else
        {
            wheel_12[wheel_num]++;
        }

        if(wheel_left[wheel_num] == 7)
        {
            wheel_left[wheel_num] = 0;
        }
        else
        {
            wheel_left[wheel_num]++;
        }
        
        if(wheel_right[wheel_num] == 7)
        {
            wheel_right[wheel_num] = 0;
        }
        else
        {
            wheel_right[wheel_num]++;
        }
        
    }
}

int check_wheel(int wheel_1, int wheel_2, int wheel_1_dir)
{
    // wheel_num_1 : 회전 된 바퀴
    // wheel_num_2 : 회전 여부를 결정할 바퀴
    // wheel_num_2 가 회전한다면 회전 방향(-1, 1), 하지 않는다면 0

    if(wheel_1 < wheel_2)
    {   
        if(wheel_right[wheel_1] == wheel_left[wheel_2])
        {   // (1,2) (2,3)
            return 0;
        }
        else
        {
            if(wheel_1_dir == 1)
            {
                rotation(wheel_2, -1);
                return -1;
            }
            else // wheel_1_dir == -1
            {
                rotation(wheel_2, 1);
                return 1;
            }
        }
        
    }
    else // wheel_num_1 > wheel_num_2
    {   
        if(wheel_left[wheel_1] == wheel_right[wheel_2])
        {   // (2,1) (4,3)
            return 0;
        }
        else
        {
            if(wheel_1_dir == 1)
            {
                rotation(wheel_2, -1);
                return -1;
            }
            else // wheel_1_dir == -1
            {
                rotation(wheel_2, 1);
                return 1;
            }
        }
    }   
}

void input()
{
    for(int i=1; i<=4; i++)
    {
        cin>>wheel[i];
    }
    cin>>K;
    for(int i=0; i<K; i++)
    {
        cin>>rot[0][i]>>rot[1][i];
    }
}

void solve()
{
    for(int k=0; k<K; k++)
    {
        if(rot[0][k] == 1)
        {
            rotation(1, rot[1][k]);

            int res_2 = check_wheel(1, 2, rot[1][k]);
            
            if(res_2 != 0)
            {
                int res_3 = check_wheel(2, 3, res_2);
                if(res_3 != 0)
                {
                    check_wheel(3, 4, res_3);
                }
            } 
        }

        else if (rot[0][k] == 2)
        {
            rotation(2, rot[1][k]);
            int res_1 = check_wheel(2, 1, rot[1][k]);

            int res_3 = check_wheel(2, 3, rot[1][k]);
            if(res_3 != 0)
            {
                int res_4 = check_wheel(3, 4, res_3);
            }
        }

        else if (rot[0][k] == 3)
        {
            rotation(3, rot[1][k]);
            int res_2 = check_wheel(3, 2, rot[1][k]);
            
            if(res_2 != 0)
            {
                int res_1 = check_wheel(2, 1, res_2);
            }

            int res_4 = check_wheel(3, 4, rot[1][k]);
        }

        else // rot[0][k] == 4
        {
            rotation(4, rot[1][k]);
            int res_3 = check_wheel(4, 3, rot[1][k]);
            if(res_3 != 0)
            {
                int res_2 = check_wheel(3, 2, res_3);
                if(res_2 != 0)
                {
                    check_wheel(2, 1, res_2);
                }
            }
        }
    }

    for(int i=1; i<=4; i++)
    {
        cout<<i<<"_12 : "<<wheel_12[i]<<"\n";
        
    }
    
 
    return;
}

int main()
{
    input();
    solve();
    return 0;
}
