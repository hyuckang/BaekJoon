#include<iostream>

using namespace std;
int N, M, H;
int map[11][31];

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

bool go_sadari()
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

void make_sadari(int cnt)
{
    
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
    // 사다리 
}

int main()
{
    input();
    pr_map();
    solve();
    return 0;
}
