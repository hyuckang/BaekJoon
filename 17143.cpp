#include<iostream>
#include<cstring>
using namespace std;
int R, C, M, king, shark_res;
int dr[] = {0, -1,1,0,0};
int dc[] = {0, 0,0,1,-1};
typedef struct
{
    int s;
    int d;
    int z;
}shark;
shark shark_map[111][111];
shark next_shark_map[111][111];

void input();
void pr_map();
int catch_shark(int);
void move_shark(int, int);
int change_dir(int);
void move_shark(int r, int c)
{
    int dir = shark_map[r][c].d;
    int s = shark_map[r][c].s;
    int z = shark_map[r][c].z;
    int nr = r, nc = c;
    // cout<<"---\n";
    // cout<<"r : "<<r<<", c : "<<c<<", dir : "<<dir<<"\n";
    for(int i=0; i<s; i++)
    {
        nr += dr[dir];
        nc += dc[dir];
        if(nr <= 0 || nr > R || nc <=0 || nc > C)
        {
            dir = change_dir(dir);
            nr += dr[dir], nc += dc[dir];
            nr += dr[dir], nc += dc[dir];
        }
    }
    // cout<<"nr : "<<nr<<", nc : "<<nc<<", dir : "<<dir<<"\n";
    // getchar();
    if(next_shark_map[nr][nc].z < shark_map[r][c].z)
    {
        next_shark_map[nr][nc].s = shark_map[r][c].s;
        next_shark_map[nr][nc].z = shark_map[r][c].z;
        next_shark_map[nr][nc].d = dir;
    }
    /*
    next_shark_map[nr][nc].s = shark_map[r][c].s;
    next_shark_map[nr][nc].z = shark_map[r][c].z;
    next_shark_map[nr][nc].d = dir;
    */
    
}
void solve()
{
    while(true)
    {
        // 낚시왕이 오른쪽으로 한 칸 이동한다.
        king++;
        if(king == C+1) break;
        
        // 낚시
        shark_res += catch_shark(king);
        
        // 상어 이동
        memset(next_shark_map, 0, sizeof(next_shark_map));
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {
                if(shark_map[i][j].z != 0)
                {
                    move_shark(i, j);
                }
            }
        }
        memcpy(shark_map, next_shark_map, sizeof(shark_map));

    }
    // cout<<"res : "<<shark_res<<"\n";
    cout<<shark_res;
}
int main()
{
    input();
    // pr_map();
    solve();
    return 0;
}
int catch_shark(int c)
{
    // 낚시왕에 있는 열에서 땅과 가장 가까운 상어를 잡는다.
    // 그 칸은 빈칸이 되고 가까운 상어의 크기가 반환
    int res = 0;
    for(int r=1; r<=R; r++)
    {
        if(shark_map[r][c].z != 0)
        {
            res = shark_map[r][c].z;
            shark_map[r][c].s = 0;
            shark_map[r][c].d = 0;
            shark_map[r][c].z = 0;
            break;
        }
    }
    return res;
}
void input()
{
    cin>>R>>C>>M;
    int r, c;
    for(int i=0; i<M; i++)
    {
        cin>>r>>c;
        cin>>shark_map[r][c].s>>shark_map[r][c].d>>shark_map[r][c].z;
    }
}
void pr_map()
{
    cout<<"=== size ===\n";
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if(shark_map[i][j].z)
            {
                cout<<shark_map[i][j].z<<" ";
            }
            else
            {
                cout<<"0 ";
            }
            
        }
        cout<<"\n";
    }
    /*
    cout<<"=== dir ===\n";
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if(shark_map[i][j].d)
            {
                cout<<shark_map[i][j].d<<" ";
            }
            else
            {
                cout<<"0 ";
            }
            
        }
        cout<<"\n";
    }
    */
}
int change_dir(int dir)
{
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else if(dir == 4) return 3;
}
