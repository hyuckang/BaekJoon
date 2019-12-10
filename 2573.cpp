#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N,M;
int maps[301][301];
bool maps_check[301][301];
int next_maps[301][301];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs()
{
    memset(maps_check, false, sizeof(maps_check));
    int area = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(maps[i][j]==0 || maps_check[i][j]) continue;
            
            area++;
            queue<pair<int,int>> Q;
            Q.push({i,j});
            maps_check[i][j] = true;
            while(!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for(int dir=0;dir<4;dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                    if(maps[nx][ny]==0 || maps_check[nx][ny]) continue;
                    
                    Q.push({nx,ny});
                    maps_check[nx][ny] = true;
                }
            }
        }
    }
    if(area==0){
        return 0;
    }
    return area;
}
int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cin>>maps[i][j];
        }
    }
    
    int year = 0;
    int result;
    do{
        memcpy(next_maps, maps, sizeof(next_maps));
        year++;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(maps[i][j]==0) continue;
                for(int dir=0;dir<4;dir++)
                {   
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
                    if(maps[nx][ny]==0 && next_maps[i][j]>0)
                        next_maps[i][j]--;
                }
            }
        }
        memcpy(maps,next_maps,sizeof(maps));
        result = bfs();
        if(result==0){
            year = 0;
            break;
        }
    }while(result<2);
    
    cout<<year;
    
    return 0;
}