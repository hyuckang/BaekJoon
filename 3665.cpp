#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

struct NODE
{
    int in, out, num;
};
int TC, N, M;

bool cmp(NODE &A, NODE &B)
{
    if(A.in > B.in)
        return false;
    else if(A.in < B.in)
        return true;    
    else
        return false;
}
void solve()
{
    NODE rank[505];
    // team_num과 순위를 매핑
    map<int, int> MP;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int team_num;
        cin >> team_num;
        rank[i].num = team_num;
        rank[i].in = i, rank[i].out = N - i - 1;        
        MP[team_num] = i;
    }

    cin >> M;
    for(int i=0; i<M; i++)
    {
        int team1, team2;
        cin >> team1 >> team2;
        int team1_rank = MP[team1], team2_rank = MP[team2];
        
        if(team1_rank < team2_rank)
        {
            // team1이 선순위, team2가 후순위
            rank[team1_rank].in++, rank[team1_rank].out--;
            rank[team2_rank].in--, rank[team2_rank].out++;
        }
        else
        {
            // team1이 후순위, team2이 선순위
            rank[team1_rank].in--, rank[team1_rank].out++;
            rank[team2_rank].in++, rank[team2_rank].out--;
        }
    }

    // indegree로 정렬
    sort(rank, rank + N, cmp);
    
    // 일관성 검사
    for(int i=0; i<N-1; i++)
    {
        if(rank[i].in == rank[i + 1].in)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    // 일관성 검사 통과
    for(int i=0; i<N; i++)
        cout << rank[i].num << " ";
    cout<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> TC;
    while(TC--)
    {
        solve();
    }
    return 0;
}
