/*
    1. 터질 것은 한번에 터져야 하기 때문에 맵을 돌면서 터트릴 것 map에 그린다.
    2. 터질 것들이 정해지면 map에 .으로 그린다.
    3. 블럭을 내린다.
    4. 더 이상 터질것이 없을 때까지 반복한다.
*/
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

char map[13][7];
bool vist_map[13][7];   
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

bool block_down()
{
    // 터질 블록이 있으면 터트리고, 터질블록이 없으면 false를 반환
    bool down = false;
    cout<<"cnt = "<<cnt<<"\n";
    // 터질 블록이 있음, retrun true cnt++
    for(int i=1; i<7; i++)
    {
        for(int j=12; j>1; j--)
        {
            if(map[j][i] == '.' && map[j-1][i] != '.')
            {
                cout<<"map[j][i] : "<<map[j][i]<<" map[j-1][i] : "<<map[j-1][i]<<"\n";
                cout<<"i = "<<i<<" j = "<<j<<"\n";
                swap(map[j][i], map[j-1][i]);
                down = true;
                pr_map();
                getchar();
                if(j<10)
                {
                    j = j+2;
                }
                else if(j==11)
                {
                    j = 13;
                }
                else if(j==12) continue;
                
            }
        }
    }
    
    if(down)
    {
        cnt++;
        return down;
    }
    
    // 터질블록이 없음
    return down;
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
}

void solve()
{
    while(true){
        memset(vist_map, false, sizeof(vist_map));
        
        for(int i=1; i<=12; i++)
        {
            for(int j=1; j<=6; j++)
            {
                // 터질 블록들 찾기
                if(map[i][j] == '.' || vist_map[i][j]) continue;

                queue<pair<int, int>> Q;
                Q.push({i, j});  vist_map[i][j] = true;
                vector<pair<int, int>> puyo_vector;     // 방문한 곳을 저장 할 벡터, 이후에 4개 이상 들어가면 터트릴 것 임
                puyo_vector.push_back({i, j});
           
                while(!Q.empty())
                {
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir=0; dir<4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx<=0 || nx>=13 || ny<=0 || ny>=7) continue; // 범위 넘어가는지                        
                        if(map[nx][ny] == '.') continue;                // .인지
                        if(vist_map[nx][ny]) continue;                  // 방문했는지
                        if(map[i][j] != map[nx][ny]) continue;          // 같은색의 블럭인지
                        
                        Q.push({nx, ny}); vist_map[nx][ny] = true;
                        puyo_vector.push_back({nx, ny});
                    }
                }
                
                // 터진 블록들을 map에 . 으로 
                if(puyo_vector.size() >= 4)
                {
                    for(int i=0; i<puyo_vector.size(); i++)
                    {
                        map[puyo_vector[i].first][puyo_vector[i].second] = '.';    
                    }
                }
                
            }
        }
        
        cout<<"blcok_down_map\n";
        pr_map();
        cout<<"=========\n";
        
        // 블록 내리기, 블록을 내릴것이 없으면 끝
        if(!block_down())
        {
            break;
        }

        // pr_map();
    }
    cout<<cnt;
}

int main()
{
    input();
    cout<<"=========\n";
    solve();
    return 0;
}
