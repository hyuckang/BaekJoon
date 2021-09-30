#include <iostream>
using namespace std;

int N, M, K;
int map[45][45], sti[15][15][105];
pair<int, int> sti_sz[105];

void rotate(int idx)
{
    int next_map[15][15];
    for(int i=0; i<sti_sz[idx].first; i++)
        for(int j=0; j<sti_sz[idx].second; j++)
            next_map[j][sti_sz[idx].first - i - 1] = sti[i][j][idx];

    swap(sti_sz[idx].first, sti_sz[idx].second);
    
    for(int i=0; i<15; i++)
        for(int j=0; j<15; j++)
            sti[i][j][idx] = next_map[i][j];
}
void attach(int r, int c, int idx)
{
    for(int i=0; i<sti_sz[idx].first; i++)
        for(int j=0; j<sti_sz[idx].second; j++)
            map[i + r][j + c] += sti[i][j][idx];
}
bool check(int r, int c, int idx)
{
    if(r + sti_sz[idx].first > N || c + sti_sz[idx].second > M)
        return false;

    for(int i=0; i<sti_sz[idx].first; i++)
        for(int j=0; j<sti_sz[idx].second; j++)
            if(map[i + r][j + c] == 1 && sti[i][j][idx] == 1) return false;

    return true;
}
void solve()
{
    for(int i=0; i<K; i++)
    {
        bool end_flag = false;
        for(int dir=0; dir<4; dir++)
        {
            for(int r=0; r<N; r++)
            {
                for(int c=0; c<M; c++)
                {
                    if(check(r, c, i))
                    {
                        attach(r, c, i);
                        end_flag = true;
                        break;
                    }
                }
                if(end_flag) break;
            }
            if(end_flag) break;
            else rotate(i);
        }
    }

    int res = 0;
    for(int r=0; r<N; r++)
        for(int c=0; c<M; c++)
            if(map[r][c] == 1) res++;

    cout << res;
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> K;
    for(int k=0; k<K; k++)
    {
        cin >> sti_sz[k].first >> sti_sz[k].second;
        for(int r=0; r<sti_sz[k].first; r++)
            for(int c=0; c<sti_sz[k].second; c++)
                cin >> sti[r][c][k];
    }
}
int main()
{
    input();
    solve();
    return 0;
}
