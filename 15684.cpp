#include<iostream>
using namespace std;
int N, M, H;
int map[31][11];
int res = 987654321;

bool can_make_sadari(int r, int c)
{
    if(map[r][c] == 0 && map[r][c+1] == 0)
    {
        return true;
    }
    return false;
}

bool check_sadari()
{
    // 그대로 내려가면 true, 그렇지 않으면 false
    for(int i=1; i<=N; i++)
    {
        int c = i;
        for(int r=1; r<=H; r++)
        {
            if(map[r][c] == 0) continue;
            else
            {
                c = c + map[r][c];
            }
        }
        if(i != c)
        {
            return false;
        }
    }
    return true;
}

void go(int r, int c, int cnt)
{
    // check_sadari 를 먼저 할 경우 cnt가 4일 경우가 res에 들어갈 수 있음
    if(4 <= cnt)
    {
        return;
    }
    
    if(check_sadari())
    {   
        // 사다리의 최솟값을 구하는 것이기 때문에 비교해주어야 함
        if(cnt < res)
        {
            res = cnt;
        }
        return;
    }

    for(int i=r; i<=H; i++)
    {
	// 마지막 열은 사다리를 놓을수 없기 때문에 j는 N-1까지
        for(int j=c; j<N; j++)
        {
            if(map[i][j] == 1 || map[i][j] == -1) continue;
            if(can_make_sadari(i, j))
            {
                map[i][j] = 1;
                map[i][j+1] = -1;
                go(i, j, cnt+1);
                map[i][j] = 0;
                map[i][j+1] = 0;
            }
        }
        c = 1;
    }
}

void input()
{
    int a, b;
    cin>>N>>M>>H;
    for(int i=0; i<M; i++)
    {
        cin>>a>>b;
        map[a][b] = 1;
        map[a][b+1] = -1;
    }
}

void solve()
{
    go(1, 1, 0);
    if(res != 987654321)
    {
        cout<<res<<"\n";
    }
    else
    {
        cout<<"-1\n";
    }
}

int main()
{
    input();
    solve();
    return 0;
}
