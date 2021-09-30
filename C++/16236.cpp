#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

struct NODE{
	int r, c, size = 2, eat = 0;
};

int N;
int map[25][25], vist[25][25];
int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
NODE shark;

vector<tuple<int, int, int>> BFS()
{
    vector<tuple<int, int, int>> fishes;

    memset(vist, -1, sizeof(vist));
    queue<pair<int, int>> Q;
    vist[shark.r][shark.c] = 0;
    Q.push(make_pair(shark.r, shark.c));

    while(!Q.empty())
    {
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++)
        {
            int nr = cur.first + dr[dir], nc = cur.second + dc[dir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
            if(vist[nr][nc] > -1 || map[nr][nc] > shark.size) continue;

            vist[nr][nc] = vist[cur.first][cur.second] + 1;
            Q.push(make_pair(nr, nc));
            
            if(0 < map[nr][nc] && map[nr][nc] < shark.size)
            {
                fishes.push_back(make_tuple(vist[nr][nc], nr, nc));
            }    
        }
    }
    return fishes;
}
void solve()
{
    int time = 0;
    while(true)
    {
        vector<tuple<int, int, int>> fishes = BFS();
        if(fishes.size() == 0) break;

        sort(fishes.begin(), fishes.end());
        int cost, r, c;
        tie(cost, r, c) = fishes[0];

        // 시간 계산
        time += cost;

        // 상어 이동
        map[shark.r][shark.c] = 0;
        shark.r = r, shark.c = c;
        map[shark.r][shark.c] = 9;
        
        // 먹은 물고기 갯수 계산
        shark.eat++;
        if(shark.size == shark.eat)
        {
            shark.size++;
            shark.eat = 0;
        }
    }
    cout << time;
}
void input()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
    cin >> N;
	for(int r=0; r<N; r++)
	{
		for(int c=0; c<N; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == 9)
				shark.r = r, shark.c = c;
		}
	}
}
int main()
{
	input();
	solve();
	return 0;
}
