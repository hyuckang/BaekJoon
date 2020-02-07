#include<iostream>
#include<cstring>
using namespace std;
int R, C, T, dust_cnt;
int map[51][51];     
int dust_map[51][51];   // 옆에서 얻은 먼지
int wind_map[51][51];
bool vist[51][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int air_condition_row;

void go_dust(int r, int c)
{
    int dust = map[r][c] / 5;
    int cnt = 0;
    for(int dir=0; dir<4; dir++)
    {
        int nx = r + dx[dir];
        int ny = c + dy[dir];
        if(nx<=0 || nx>R || ny<=0 || ny>C) continue;
        if(map[nx][ny] == -1) continue;

        cnt++;
        dust_map[nx][ny] = dust_map[nx][ny] + dust;        
    }
    map[r][c] = map[r][c] - (dust * cnt);
}

void go_wind(int r, int c)
{
    if(c == 1)
    {
        if(r < air_condition_row-1)
        {
            if(map[r+1][c] == -1)
            {
                wind_map[r+1][c] = -1;
            }
            else
            {
                wind_map[r+1][c] = map[r][c];
            }
        }
        else if(air_condition_row < r)
        {
            if(map[r-1][c] == -1)
            {
                wind_map[r-1][c] = -1;    
            }
            else
            {
                wind_map[r-1][c] = map[r][c];
            }
        }
        
    }
    else if(c == C)
    {
        if(r == 1 || r == R)
        {
            wind_map[r][c-1] = map[r][c];
        }
        else if(r <= air_condition_row-1)
        {
            wind_map[r-1][c] = map[r][c];
        }
        else if(air_condition_row <= r)
        {
            wind_map[r+1][c] = map[r][c];
        }
    }
    else
    {
        if(r == 1 || r == R)
        {
            wind_map[r][c-1] = map[r][c];
        }
        else if(r == air_condition_row-1 || r == air_condition_row)
        {
            wind_map[r][c+1] = map[r][c];
        }
        else
        {
            wind_map[r][c] = map[r][c];
        }
    }
} 

void input()
{
    cin>>R>>C>>T;    
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            cin>>map[i][j];
            if(map[i][j] == -1)
            {
                air_condition_row = i;  // 공기청정기의 행
            }
        }
    }
}

void solve()
{
    while(T--)
    {
        memset(vist, false, sizeof(vist));
        memset(dust_map, 0, sizeof(dust_map));
        memset(wind_map, 0, sizeof(wind_map));

        // 퍼진 먼지가 다시 퍼지면 안 됨
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {
                if(map[i][j] > 0)
                {
                    vist[i][j] = true;
                }
            }
        }

        // 미세먼지 확산
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {
                if(map[i][j] >= 5 && vist[i][j])
                {
                    go_dust(i, j);
                }
            }
        }

        // 기존 미세먼지와 받은 미세먼지를 더 해준다
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {   
                map[i][j] = map[i][j] + dust_map[i][j];
            }
        }
        
        // 공기청정기 작동
        for(int i=1; i<=R; i++)
        {
            for(int j=1; j<=C; j++)
            {
                if(map[i][j] == 0) continue;
                else if(map[i][j] == -1)
                {
                    wind_map[i][j] = -1;
                }
                else
                {
                    go_wind(i, j);
                }
            }
        }

        memcpy(map, wind_map, sizeof(wind_map));

    }

    dust_cnt = 0;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if(map[i][j] == -1) continue;
            dust_cnt += map[i][j];
        }    
    }
    cout<<dust_cnt<<"\n";
}
int main()
{ 
    input();
    solve();
}
