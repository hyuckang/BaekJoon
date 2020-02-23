#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

typedef struct 
{
    int r;
    int c;
    int dir;
}H;

int N, K;   // 4 <= K <= 10
int map[13][13];
H horses[11];
vector<int> map_horse[13][13];

int cnt;    // 턴의 번호
int dr[] = {0, 0, 0, -1, 1};
int dc[] = {0, 1, -1, 0, 0};


int go_check_hosre(int k)
{
    // 말이 이동하려는 칸 체크하여 정수(int)를 돌려줌
    int horse_flag = 0;
    int nr = horses[k].r + dr[horses[k].dir];
    int nc = horses[k].c + dc[horses[k].dir];
    
    
    if(nr<=0 || nr>N || nc<=0 || nc>N)
    {
        // 체스판을 벗어나는 경우 또한 Blue
        horse_flag = 2;
    }
    else
    {
        horse_flag = map[nr][nc];
    }
    
    
    if(horse_flag == 0)
    {
        // 이동하려는 칸이 White
        
    }
    else if(horse_flag == 1)
    {
        // 이동하려는 칸이 Red

        
    }
    else if(horse_flag == 2)
    {
        // 이동하려는 칸이 Blue
        
    }

    return 0;   
}


void input()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }

    for(int i=1; i<=K; i++)
    {
        cin>>horses[i].r>>horses[i].c>>horses[i].dir;
    }

    for(int i=1; i<=K; i++)
    {
        map_horse[horses[i].r][horses[i].c].push_back(i);
    }
}

void solve()
{
    // while 종료체크에서 나가기 전까지

    // 턴 번호 1 증가
    cnt++;


    for(int i=1; i<=K; i++)
    {    
        go_check_hosre(i);  // i번째 말이 이동검사
    }
    
    // 종료 체크
}

int main()
{
    input();
    solve();
    return 0;
}
