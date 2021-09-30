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
    // 0 : 왼쪽 청소 가능, 1 : 왼쪽 청소 불가능
    // 2 : 4방향 모두 청소 불가능, 3 : 4방향 모두 청소 불가능 & 후진 불가능
    int left_r = r + check_r[dir];
    int left_c = c + check_c[dir];
    if(map[left_r][left_c] || vist[left_r][left_c])
    {
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
            int next_r = r + back_r[dir];
            int next_c = c + back_c[dir];
            if(map[next_r][next_c])
            {
                return 3;
            }
            else
            {
                return 2;
            }
        }
        else
        {
            return 1;
        }      
    }
    else
    {   
        // 청소 가능
        return 0;
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
}

void solve()
{
    clean(robot_r, robot_c);
    while(true)
    {
        int check_val = check(robot_r, robot_c, robot_dir);
        if(check_val == 0)
        {
            change_dir();
            go(robot_r, robot_c, robot_dir);
            clean(robot_r, robot_c);
        }
        else if(check_val == 1)
        {
            change_dir();
        }
        else if(check_val == 2)
        {
            back(robot_r, robot_c, robot_dir);
        }
        else if(check_val == 3)
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
