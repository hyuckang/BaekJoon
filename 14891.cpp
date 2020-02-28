#include<iostream>
#include<string>

using namespace std;

string wheel[5];
int K;
int rot[2][100], wheel_idx[4];


void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=1; i<=4; i++)
    {
        cout<<wheel[i]<<"\n";
    }
    
    cout<<K<<"\n";
    
    for(int i=0; i<K; i++)
    {
        cout<<rot[0][i]<<" "<<rot[1][i]<<"\n";
    }
}

void rotation(int wheel_num, int dir)
{
    // 바퀴 번호와 방향을 받아 바퀴를 회전시켜준다.
    if(dir == 1)
    {
        // 시계 회전
        if(wheel_idx[wheel_num] == 7)
        {
            wheel_idx[wheel_num] = 0;
        }
        else
        {
            wheel_idx[wheel_num]++;
        }
        
    }
    else if(dir == -1)
    {
        // 반시계 회전
        if(wheel_idx[wheel_num] == 0)
        {
            wheel_idx[wheel_num] = 7;
        }
        else
        {
            wheel_idx[wheel_num]--;
        }
        
    }
}

bool check_wheel(int wheel_num_1, int wheel_num_2)
{
    // wheel_num_1 : 회전 된 바퀴
    // wheel_num_2 : 회전 여부를 결정할 바퀴
    // wheel_num_2 가 회전한다면 true, 하지 않는다면 false

    return true;
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
        
            check_wheel(1, 2);
            check_wheel(2, 3);
            check_wheel(3, 4);
        }
        else if (rot[0][k] == 2)
        {
            rotation(2, rot[1][k]);
            check_wheel(2, 1);
            check_wheel(2, 3);
            check_wheel(3, 4);
        }
        else if (rot[0][k] == 3)
        {
            rotation(3, rot[1][k]);
            check_wheel(3, 2);
            check_wheel(2, 1);
            check_wheel(3, 4);
        }
        else
        {
            rotation(4, rot[1][k]);
            check_wheel(4, 3);
            check_wheel(3, 2);
            check_wheel(2, 1);
        }
    }
}

int main()
{
    input();
    // pr_map();
    solve();
    return 0;
}
