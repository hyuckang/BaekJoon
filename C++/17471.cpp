#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, min_res = 987654321;
int people[15];
vector<int> E[15];

int calc(vector<int> &A, vector<int> &B)
{
    int a_res = 0, b_res = 0;
    
    for(size_t i=0; i<A.size(); i++)
        a_res += people[A[i]];
    for(size_t i=0; i<B.size(); i++)
        b_res += people[B[i]];
        
    return abs(a_res - b_res);
}
bool check(vector<int> &A, vector<int> &B)
{
    set<int> SA, SB;
    for(size_t i=0; i<A.size(); i++)
        SA.insert(A[i]);
    for(size_t i=0; i<B.size(); i++)
        SB.insert(B[i]);

    // BFS
    int vist[15] = {0, };
    queue<int> AQ, BQ;
    AQ.push(A[0]);  vist[A[0]] = 1;
    BQ.push(B[0]);  vist[B[0]] = 2;
    while(!AQ.empty())
    {
        int cur = AQ.front(); AQ.pop();
        for(size_t i=0; i<E[cur].size(); i++)
        {
            int next = E[cur].at(i);
            if(vist[next] == 0 && SA.find(next) != SA.end())
            {
                AQ.push(next);
                vist[next] = 1;
            }
        }
    }
    while(!BQ.empty())
    {
        int cur = BQ.front(); BQ.pop();
        for(size_t i=0; i<E[cur].size(); i++)
        {
            int next = E[cur].at(i);
            if(vist[next] == 0 && SB.find(next) != SB.end())
            {
                BQ.push(next);
                vist[next] = 2;
            }
        }
    }

    for(size_t i=0; i<A.size(); i++)
        if(vist[A[i]] != 1) return false;
    for(size_t i=0; i<B.size(); i++)
        if(vist[B[i]] != 2) return false;

    return true;
}
void go(int idx, vector<int> &A, vector<int> &B)
{
    if(idx == N + 1)
    {
        if(A.size() == 0 || B.size() == 0)
            return;
        if(check(A, B))
            min_res = min(min_res, calc(A, B));
        return;
    }

    A.push_back(idx);
    go(idx + 1, A, B);
    A.pop_back();

    B.push_back(idx);
    go(idx + 1, A, B);
    B.pop_back();
}
void solve()
{
    vector<int> A, B;
    go(1, A, B);

    if(min_res == 987654321)
        cout << -1;
    else
        cout << min_res;
}
void input()
{
    cin >> N;

    for(int i=1; i<=N; i++)
        cin >> people[i];
    
    for(int i=1; i<=N; i++)
    {
        int cnt, tmp;
        cin >> cnt;
        for(int j=0; j<cnt; j++)
        {
            cin >> tmp;
            E[i].push_back(tmp);
        }
    }
}
int main()
{
    input();
    solve();
    return 0;
}
