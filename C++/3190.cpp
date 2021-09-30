#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int N, K, L, time;
int map[111][111];  // 1: 뱀, 2: 사과
int dr[] = {-1, 0, 1, 0};   // 0:북, 1:동, 2:남, 3:서
int dc[] = {0, 1, 0, -1};
vector<pair<int, char>> time_dir;
typedef struct
{
    int r;
    int c;
    int dir;
}sneak;

int change_dir(int d, char type)
{
    if(type == 'L')
    {
        if(d == 0)
        {
            return 3;
        }
        else
        {
            return d-1;
        }
    }
    else // type == 'D'
    {
        if(d == 3)
        {
            return 0;
        }
        else
        {
            return d+1;
        }
    }
}

void input()
{
    cin>>N>>K;
    for(int i=0; i<K; i++)
    {
        int r, c;
        cin>>r>>c;
        map[r][c] = 2;
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

void solve()
{
    // 꼬리를 저장하는 Q, (행, 열, 방향)으로 저장
    queue<tuple<int, int, int>> Q;
    map[1][1] = 1;
    Q.push(make_tuple(1, 1, 1));
    sneak head;
    head.r = 1, head.c = 1, head.dir = 1;
    int time_idx = 0;
    
    while(true)
    {
        time++;
        int next_r = head.r + dr[head.dir];
        int next_c = head.c + dc[head.dir];

        // 종료조건 -> 벽에 닿거나, 몸에 닿음
        if(next_r<=0 || next_r>N || next_c<=0 || next_c >N || map[next_r][next_c] == 1)
        {   
            break;
        }
        
        // 방향 검사
        if(time == time_dir[time_idx].first)
        {
            head.dir = change_dir(head.dir, time_dir[time_idx].second);
            time_idx++;
        }

        // 사과 먹음 -> 꼬리 이동 없음
        if(map[next_r][next_c] == 2)
        {
            map[next_r][next_c] = 1;
            Q.push(make_tuple(next_r, next_c, head.dir));
        }
        // 사과 먹지 못함 -> 꼬리 이동
        else
        {
            map[next_r][next_c] = 1;
            Q.push(make_tuple(next_r, next_c, head.dir));
            sneak tail;
            tie(tail.r, tail.c, tail.dir) = Q.front();
            Q.pop();
            map[tail.r][tail.c] = 0;
        }
        // 머리 이동
        head.r = next_r;
        head.c = next_c;
    }
    cout<<time<<"\n";
}
int main()
{
    input();
    solve();
    return 0;
}
