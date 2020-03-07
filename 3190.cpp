#include<iostream>
#include<vector>
using namespace std;

int N, K, L, time, legth;
int map[111][111];  // 0:빈칸, 1:사과
int sneak_map[111][111];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
vector<pair<int, char>> time_dir;
typedef struct
{   // 0:북, 1:동, 2:남, 3:서
    int r;
    int c;
    int dir;
}sneak;
sneak head;
sneak tail;
void pr_map();
void pr_sneak();
void input();
void change_dir(char dir_type);


int go_head()
{
    head.r = head.r + dr[head.dir];
    head.c = head.c + dc[head.dir];
    if(head.r <= 0 || head.r > N || head.c <= 0 || head.c > N)
    {   // 벽에 닿음, 종료
        return -1;
    }
    if(sneak_map[head.r][head.c] == 1)
    {   // 자신 몸에 닿음, 종료
        return -1;
    }

    if(map[head.r][head.c] == 1)
    {   // 사과 먹음
        sneak_map[head.r][head.c] = 1;
        return 1;
    }
    
    // 종료되지 않고, 사과 먹지 않음
    // 꼬리 이동해야함
    return 0;
}

void go_tail()
{
    sneak_map[tail.r][tail.c] = 0;
    tail.r = tail.r + dr[tail.dir];
    tail.c = tail.c + dc[tail.dir];
    sneak_map[tail.r][tail.c] = 1;
}

void solve()
{   
    head.r = 1, head.c = 1, head.dir = 1;
    tail.r = 1, tail.c = 1, tail.dir = 1;
    sneak_map[1][1] = 1;
    int check_time = 0;
    while(true)
    {
        time++;
        // 몸길이 늘려, 머리를 다음칸으로 이동
        // go_head 결과가 1 이라면 꼬리 움직이지 않는다.
        // go_head 결과가 0 이라면 꼬리또한 움직인다. go_tail();
        // go_head 결과가 -1 이라면 게임 종료
        int go_head_res = go_head();
        if(go_head_res == -1)
        {
            break;
        }
        else if(go_head_res == 0)
        {
            go_tail();
        }
        else if(go_head_res == 1)
        {
            continue;
        }
        //pr_sneak();
        //getchar();

        // 머리 방향 검사
        if(time_dir[check_time].first == time)
        {  
            //cout<<"change_dir, time : "<<time<<"\n";
            change_dir(time_dir[check_time].second);
            check_time++;
            //cout<<"head dir : "<<head.dir<<"\n";
        }

        // 꼬리 방향 검사
        

    }
    cout<<time<<"\n";
}

int main()
{   
    input();
    //pr_map();
    solve();
    
    return 0;
}

void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void pr_sneak()
{
    cout<<"=== sneak ===\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<sneak_map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void input()
{
    cin>>N>>K;
    for(int i=0; i<K; i++)
    {
        int r, c;
        cin>>r>>c;
        map[r][c] = 1;
    }
    cin>>L;
    for(int i=0; i<L; i++)
    {
        int X;
        char C;
        cin>>X>>C;
        time_dir.push_back({X, C});
    }

}
void change_dir(char dir_type)
{
    // 왼쪽, L
    if(dir_type == 'L')
    {
        if(head.dir == 0)
        {
            head.dir = 3;
        }
        else
        {
            head.dir--;
        }
    }
    // 오른쪽, R
    else if(dir_type == 'D')
    {
        if(head.dir == 3)
        {
            head.dir = 0;
        }
        else
        {
            head.dir++;
        }
    }
}
