#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct NODE
{
    int r, c, dir, idx = 0;
};
int N, K;
int map[15][15], dr[] = {0, 0, 0, -1, 1}, dc[] = {0, 1, -1, 0, 0};
NODE H[15];
vector<int> HM[15][15];

void RED(int r, int c, int idx, int nr, int nc)
{
    stack<int> ST;
    int HM_r_c_sz = HM[r][c].size();
    for(int i=idx; i<HM_r_c_sz; i++)
    {
        ST.push(HM[r][c].at(i));
        H[ST.top()].r = nr, H[ST.top()].c = nc;
        H[ST.top()].idx -= idx;
    }
    while(!ST.empty())
    {
        HM[r][c].pop_back();

        HM[nr][nc].push_back(ST.top());
        H[ST.top()].idx -= ST.size();
        H[ST.top()].idx += HM[nr][nc].size();
        ST.pop();
    }
}
void WHITE(int r, int c, int idx, int nr, int nc)
{
    queue<int> Q;
    int HM_r_c_sz = HM[r][c].size();
    for(int i=idx; i<HM_r_c_sz; i++)
    {
        Q.push(HM[r][c].at(i));
        H[Q.back()].idx -= idx;
        H[Q.back()].idx += HM[nr][nc].size();
        H[Q.back()].r = nr, H[Q.back()].c = nc;
    }
    while(!Q.empty())
    {
        HM[r][c].pop_back();

        HM[nr][nc].push_back(Q.front());
        Q.pop();
    }
}
int change_dir(int dir)
{
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else return 3;
}
void solve()
{
    int turn = 1;
    while(true)
    {
        if(turn > 1000)
        {
            cout << -1;
            return;
        }
        
        for(int i=1; i<=K; i++)
        {
            int nr = H[i].r + dr[H[i].dir];
            int nc = H[i].c + dc[H[i].dir];
            
            if(nr < 1 || nr > N || nc < 1 || nc > N || map[nr][nc] == 2)
            {
                H[i].dir = change_dir(H[i].dir);    
                nr = H[i].r + dr[H[i].dir];         
                nc = H[i].c + dc[H[i].dir];
                if(nr < 1 || nr > N || nc < 1 || nc > N || map[nr][nc] == 2)
                    continue;
                else if(map[nr][nc] == 0)
                    WHITE(H[i].r, H[i].c, H[i].idx, nr, nc);
                else if(map[nr][nc] == 1)
                    RED(H[i].r, H[i].c, H[i].idx, nr, nc);
            } 
            else if(map[nr][nc] == 0)
                WHITE(H[i].r, H[i].c, H[i].idx, nr, nc);
            else if(map[nr][nc] == 1)
                RED(H[i].r, H[i].c, H[i].idx, nr, nc);

            if(HM[nr][nc].size() >= 4)
            {
                cout << turn;
                return;
            }
        }
        turn++;
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for(int r=1; r<=N; r++)
        for(int c=1; c<=N; c++)
            cin >> map[r][c];
    for(int i=1; i<=K; i++)
    {
        cin >> H[i].r >> H[i].c >> H[i].dir;
        HM[H[i].r][H[i].c].push_back(i);
    }
}
int main()
{
    input();
    solve();
    return 0;
}
