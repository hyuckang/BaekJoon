#include<iostream>
#include<cstring>
using namespace std;
int N;
int map[25][25], vote_map[25][25];
void pr_vote();
void vote(int x, int y, int d1, int d2)
{
    memset(vote_map, 0, sizeof(vote_map));

    for(int r=1; r<=N; r++)
    {
        for(int c=1; c<=N; c++)
        {
            if(r < x + d1 && c <= y)
            {
                vote_map[r][c] = 1;
            }
            else if( r <= x + d2 && y < c)
            {
                vote_map[r][c] = 2;
            }
            else if( x + d1 <= r && c < y - d1 + d2)
            {
                vote_map[r][c] = 3;
            }
            else if ( x + d2 < r && y - d1 + d2 <= c)
            {
                vote_map[r][c] = 4;
            }
        }
    }
    
    for(int d=0; d<=d1; d++)
    {
        vote_map[x + d][y -d] = 5; // 1
        vote_map[x + d2 + d][y + d2 - d] = 5; // 4
    }
    for(int d=0; d<=d2; d++)
    {
        vote_map[x + d][y + d] = 5; // 2
        vote_map[x + d1 + d][y - d1 + d] = 5; // 3
    }

}
void solve()
{
    // (x, y) d1, d2 구하기
    // 1 <= x < x+d1+d2 <= N
    // 1 <= y-d1 < y < y+d2 <= N
    //////////////////////////////

    for(int x=1; x<=N; x++)
    {
        for(int y=1; y<=N; y++)
        {
            for(int d1=1; d1<=N; d1++)
            {
                for(int d2=1; d2<=N; d2++)
                {
                    if(x + d1 + d2 > N) continue;
                    if(1 > y-d1) continue;
                    if(y + d2 > N) continue;
                    cout<<"x :"<<x<<", y : "<<y<<", d1 : "<<d1<<", d2 : "<<d2<<"\n";
                    vote(x, y, d1, d2);
                    pr_vote();
                    getchar();
                    
                }
            }            
        }
    }
}
void input()
{
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
void pr_vote()
{
    cout<<"=== vote ===\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<vote_map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
