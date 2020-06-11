/*
    bfs -> 큐에 돌려야 하는 바퀴의 번호와 방향을 넣는다.
*/

#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int K, vist[5], dir[] = {-1, 1};
string wheel[5];

bool check(int n1, int n2)
{

}
void rotate(int n, int d)
{
    
}
void solve()
{
    for(int i=0; i<K; i++)
    {
        
        int n, d;
        cin >> n >> d;

        memset(vist, 0, sizeof(vist));
        // first : 바퀴 번호, second : 방향
        queue<pair<int, int>> Q;

        vist[n] = 1;
        Q.push(make_pair(n, d));
        
        while(!Q.empty())
        {
            pair<int, int> cur = Q.front(); Q.pop();
            rotate(cur.first, cur.second);
            for(int i=0; i<2; i++)
            {
                int next = cur.first + dir[i];
                if(0 >= next || next > 4 || vist[next]) continue;
                if(check(cur.first, next))
                {
                    vist[next] = 1;
                    Q.push(make_pair(next, cur.second * -1));
                }
            }   
        }
    }
    

}
void input()
{
    for(int i=1; i<5; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin >> wheel[i];
        }
    }
    
    cin >> K;
}
int main()
{
    input();
    solve();
    return 0;
}
