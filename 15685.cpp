/*
    드래곤 커브를 N번 map에 그린다
    i세대 드래곤 커브라면 2^i
    최대 10세대 -> 2^10 = 1024
*/

#include<iostream>

using namespace std;

int N, X, Y, D, G;;
int map[105][105];

void turn_dir(int dir)
{
    
}
void solve()
{
    int X, Y, D, G;
    for(int i=0; i<N; i++)
    {
        cin>>X>>Y>>D>>G;
        map[Y][X] = 1;

        // 0세대부터 G세대 까지
        // D = turn_dir(D);
    }

    // 정사각형 체크
    int cnt = 0;
    for(int r=0; r<100; r++)
    {
        for(int c=0; c<100; c++)
        {
            if(map[r][c] == 0 && map[r][c + 1] == 0 && map[r + 1][c] == 0 && map[r + 1][c + 1]) cnt++;
        }
    }
    cout<<cnt;
}
void input()
{
    cin>>N;
}
int main()
{
    input();
    solve();
    return 0;
}
