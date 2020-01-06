/*
    1. 맵을 돌면서 터트릴것 정해놓기
    2. 밑에가 비었으면 밑으로 내리기
*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

char map[13][7];
bool vist_map[13][7];   
bool puyo_map[13][7];   // 터지는 맵들 저장
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt = 0;            // 몇 연쇄인지 저장

void pr_map()
{
    cout<<"map\n";
    for(int i=1; i<13; i++)
    {
        for(int j=1; j<7; j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void input()
{
    for(int i=1; i<13; i++)
    {
        for(int j=1; j<7; j++)
        {
            cin>>map[i][j];
        }
    }
    pr_map();
}

void pr_puyo_map()
{
    cout<<"puyo_map\n";
    for(int i=1; i<13; i++)
    {
        for(int j=1; j<7; j++)
        {
            cout<<puyo_map[i][j];
        }
        cout<<"\n";
    }
}



bool block_down()
{
    // 터질 블록이 있으면 터트리고, 터질블록이 없으면 false를 반환
    for(int i=1; i<13; i++)
    {
        for(int j=1; j<7; j++)
        {
            if(puyo_map[i][j])
            {
                // 터트리기 
            }
        }
    }        
    return false;
}

void solve()
{
        memset(vist_map, false, sizeof(vist_map));
        memset(puyo_map, false, sizeof(puyo_map));
        
        for(int i=1; i<13; i++)
        {
            for(int j=1; j<7; j++)
            {
                // 터질 블록들 찾기
                if(map[i][j] == '.' || vist_map[i][j]) continue;

                queue<pair<int, int>> Q;
                Q.push({i, j});  vist_map[i][j] = true;
                vector<pair<int, int>> puyo_vector;
                while(!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<1 || nx>13 || ny<1 || ny>7) continue;     // 범위 넘어가는지
                        if(vist_map[ny][ny]) continue;                  // 방문 했는지
                        if(map[i][j] != map[nx][ny]) continue;          // 같은색의 블럭인지

                        Q.push({nx, ny}); vist_map[nx][ny] = true;
                        puyo_vector.push_back({nx, ny});
                    }
                }

                // 터질 블록을 puyo_map에 저장
                if(puyo_vector.size() >= 4)
                {
                    for(int i=0; i<puyo_vector.size(); i++)
                    {
                        puyo_map[puyo_vector[i].first][puyo_vector[i].first] = true;
                    }
                }
            }
        }
        pr_puyo_map();

}

int main()
{
    input();
    solve();
    return 0;
}