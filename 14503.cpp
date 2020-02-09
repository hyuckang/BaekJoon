#include<iostream>
#include<cstring>

using namespace std;

int N, M;
int robot_r, robot_c, robot_dir, res;
int map[51][51];
bool vist[51][51];
int check_r[] = {0, -1, 0, 1};
int check_c[] = {-1, 0, 1, 0};
int go_r[] = {-1, 0, 1, 0};
int go_c[] = {0, 1, 0, -1};
int back_r[] = {1, 0, -1, 0};
int back_c[] = {0, -1, 0, 1};

void back(int r, int c, int dir)
{
    robot_r = r + back_r[dir];
    robot_c = c + back_c[dir];
}

void go(int r, int c, int dir)
{
    robot_r = r + go_r[dir];
    robot_c = c + go_c[dir];
}

void clean(int r, int c)
{
    res++;
    vist[r][c] = true;
}

int check(int r, int c, int dir)
{
    // 상하좌우 모두 청소 했거나 모두 벽 -> -1(후진 가능), -2(후진까지 할 수 없음)
    int cnt = 0;
    for(int dirs=0; dirs<4; dirs++)
    {
        int next_r = r + check_r[dirs];
        int next_c = c + check_c[dirs];
        if(map[next_r][next_c] || vist[next_r][next_c])
        {
            cnt++;
        }
    }
    if(cnt == 4)
    {
        int next_back_r = r + back_r[dir];
        int next_back_c = c + back_c[dir];
        if(map[next_back_r][next_back_c])
        {
            return -2;
        }
        else
        {
            return -1;
        }
    }

    // 왼쪽이 청소가 불가능하면 0, 왼쪽 청소가 가능하면 1
    int left_r = r + check_r[dir];
    int left_c = c + check_c[dir];
    // cout<<"left_r : "<<left_r<<" "<<"left_c : "<<left_c<<"\n";
    if(map[left_r][left_c] || vist[left_r][left_c])
    {
        // 벽이거나 청소했음

        
        return 0;
    }
    else
    {
        return 1;
    }
    
}

void change_dir()
{
    if(robot_dir == 0)
    {
        robot_dir = 3;
    }
    else
    {
        robot_dir--;
    } 
}

void init()
{
    res = 0;
    memset(vist, false, sizeof(vist));
}

void input()
{
    cin>>N>>M;
    cin>>robot_r>>robot_c>>robot_dir;
    for(int r=0; r<N; r++)
    {
        for(int c=0; c<M; c++)
        {
            cin>>map[r][c];
        }
    }

    // robot_r = start_r, robot_c = start_c, robot_dir = start_dir;
}

void solve()
{
    clean(robot_r, robot_c);
    while(true)
    {
        cout<<"robot_r : "<<robot_r<<" robot_c : "<<robot_c<<" robot_dir : "<<robot_dir<<"\n";
        int check_val = check(robot_r, robot_c, robot_dir);
        cout<<"check_val : "<<check_val<<"\n\n";
        getchar();
        if(check_val == 0)
        {
            // 왼쪽 청소 불가능
            change_dir();
            change_dir();
        }
        else if(check_val == 1)
        {
            // 왼쪽 청소 가능
            change_dir();
            go(robot_r, robot_c, robot_dir);
            clean(robot_r, robot_c);
        }
        else if(check_val == -1)
        {
            back(robot_r, robot_c, robot_dir);
        }
        else if(check_val == -2)
        {
            break;
        }
    }
    cout<<res<<"\n";

}

int main()
{
    init();
    input();
    solve();
    return 0;
}
