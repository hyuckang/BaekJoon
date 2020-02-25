#include<iostream>

using namespace std;

int N, M, H;
int map[11][31];
int res = 987654321;

void pr_map()
{
    
    for(int i=1; i<=H; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<map[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
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
    // 그대로 내려가면 return true
    // 그대로 내려가지 않으면 return false
    for(int i=1; i<=N; i++)
    {
        // cout<<i<<" -> ";
        int c = i;
        for(int r=1; r<=H; r++)
        {
            if(map[r][c] == 0) continue;
            else
            {
                c = c + map[r][c];
            }
        }
        // cout<<c<<"\n";

        if(i != c)
        {
            return false;
        }
    }
    return true;
}

void go(int r, int c, int cnt)
{
    if(check_sadari())
    {
        res = cnt;
        return;
    }

    if(4 <= cnt)
    {
        return;
    }

    for(int i=r; i<=H; i++)
    {
        for(int j=c; j<N; j++)
        {
            if(map[i][j] == 1 || map[i][j] == -1) continue;
            if(can_make_sadari(i, j))
            {
                map[i][j] = 1;
                map[i][j+1] = -1;
                cout<<"make_sadari : "<<i<<" "<<j<<"\n";
                go(i, j, cnt+1);
                cout<<"remove_sadari : "<<i<<" "<<j<<"\n";
                map[i][j] = 0;
                map[i][j+1] = 0;
            }
        }
        c = 0;
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
