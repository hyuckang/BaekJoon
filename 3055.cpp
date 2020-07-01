#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int R, C, vist[55][55][2];
char map[55][55];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
vector<pair<int, int>> water;
pair<int, int> st, dst;

int bfs()
{
	memset(vist, -1, sizeof(vist));
	
	// water bfs, vist[r][c][0]
	queue<pair<int, int>> Q1;
	int water_sz = water.size();
	for(int i=0; i<water_sz; i++)
	{
		vist[water[i].first][water[i].second][0] = 0;
		Q1.push(water[i]);
	}
	while(!Q1.empty())
	{
		pair<int, int> cur = Q1.front(); Q1.pop();
		for(int dir=0; dir<4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || vist[nr][nc][0] >= 0) continue;
			if(map[nr][nc] == 'X' || map[nr][nc] == 'D') continue;
			
			vist[nr][nc][0] = vist[cur.first][cur.second][0] + 1;
			Q1.push(make_pair(nr, nc));
		}
	}
	
	// escape bfs, vist[r][c][1]
    queue<pair<int, int>> Q2;
    vist[st.first][st.second][1] = 0;
	Q2.push(st);
	while(!Q2.empty())
	{
		pair<int, int> cur = Q2.front(); Q2.pop();

		if(cur.first == dst.first && cur.second == dst.second)
			return vist[dst.first][dst.second][1];
        
		for(int dir=0; dir<4; dir++)
		{
			int nr = cur.first + dr[dir];
			int nc = cur.second + dc[dir];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(map[nr][nc] == 'X' || vist[nr][nc][1] >= 0) continue;
            // 물이 안찼거나, 도착지점이거나, 갈수 있을 경우
            if(vist[nr][nc][0] == -1 || map[nr][nc] == 'D' || vist[nr][nc][0] > vist[cur.first][cur.second][1] + 1)
            {
    			vist[nr][nc][1] = vist[cur.first][cur.second][1] + 1;
			    Q2.push(make_pair(nr, nc));
            }     
		}
	}
	
    return -1;
}
void input()
{
	cin >> R >> C;
	for(int i=0; i<R; i++)
	{
		for(int j=0; j<C; j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 'S')
				st.first = i, st.second = j;
			else if(map[i][j] == 'D')
				dst.first = i, dst.second = j;
			else if(map[i][j] == '*')
				water.push_back(make_pair(i, j));
		}
	}
}
void solve()
{
	int res = bfs();
	if(res == -1)
		cout << "KAKTUS";
	else
		cout << res;
}
int main()
{
	input();
	solve();
	return 0;
}
