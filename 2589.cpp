#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int R, C;
string map[55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
int vist[55][55], max_res = -987654321;

void bfs(int st_r, int st_c)
{
	memset(vist, -1, sizeof(vist));
	
	queue<pair<int, int>> Q;
	vist[st_r][st_c] = 0;
	Q.push(make_pair(st_r, st_c));
	
	while(!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for(int dir=0; dir<4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(map[nr][nc] == 'W' || vist[nr][nc] >= 0) continue;
			
			vist[nr][nc] = vist[cur.first][cur.second] + 1;
			Q.push(make_pair(nr, nc));
			
			// 최대 거리 갱신
			max_res = max(max_res, vist[nr][nc]);
		}
	}
}

void solve()
{
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
            if(map[i][j] == 'L')
			{
				bfs(i, j);
			}
		}
	}
	
	cout << max_res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
	cin >> R >> C;
	for(int i=0; i<R; i++)
        cin >> map[i];
}
int main()
{
	input();
	solve();
  return 0;
}
