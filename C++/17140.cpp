#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int row = 3, col = 3, time = 0;
int A[105][105], cnt[105], r, c, k;

bool cmp(pair<int, int> A, pair<int, int> B)
{
    if(A.second == B.second)
        return A.first < B.first;
    else
        return A.second < B.second;
}
void R()
{
    int max_col = -987654321;
    vector<int> sorted[105];
    for(int i=1; i<=row; i++)
    {
        // 빈도수 세기
        memset(cnt, 0, sizeof(cnt));
        for(int j=1; j<=col; j++)
            cnt[A[i][j]]++;
        
        // 정렬하기
        vector<pair<int, int>> V;
        for(int j=1; j<=100; j++)
        {
            if(cnt[j] == 0) continue;
            V.push_back(make_pair(j, cnt[j]));
        }
        int V_sz = V.size();
        sort(V.begin(), V.end(), cmp);

        // 한꺼번에 A에 넣기 위해 sorted에 저장
        for(int j=0; j<V_sz; j++)
        {
            sorted[i].push_back(V[j].first);
            sorted[i].push_back(V[j].second);
        }
        int sorted_sz = sorted[i].size();
        max_col = max(max_col, sorted_sz);
    }
    
    if(max_col > 100)
        max_col = 100;

    // A에 저장
    for(int i=1; i<=row; i++)
    {
        int sorted_sz = sorted[i].size();
        for(int j=0; j<sorted_sz; j++)
            A[i][j + 1] = sorted[i].at(j);
        for(int j=sorted_sz; j<=max_col; j++)
            A[i][j + 1] = 0;
    }
    col = max_col;
}
void C()
{
    int max_row = -987654321;
    vector<int> sorted[105];
    for(int i=1; i<=col; i++)
    {
        memset(cnt, 0, sizeof(cnt));
        for(int j=1; j<=row; j++)
            cnt[A[j][i]]++;
        
        vector<pair<int, int>> V;
        for(int j=1; j<=100; j++)
        {
            if(cnt[j] == 0) continue;
            V.push_back(make_pair(j, cnt[j]));
        }
        int V_sz = V.size();
        sort(V.begin(), V.end(), cmp);

        for(int j=0; j<V_sz; j++)
        {
            sorted[i].push_back(V[j].first);
            sorted[i].push_back(V[j].second);
        }
        int sorted_sz = sorted[i].size();
        max_row = max(max_row, sorted_sz);
    }

    if(max_row > 100)
        max_row = 100;

    for(int i=1; i<=col; i++)
    {
        int sorted_sz = sorted[i].size();
        for(int j=0; j<sorted_sz; j++)
            A[j + 1][i] = sorted[i].at(j);
        for(int j=sorted_sz; j<=max_row; j++)
            A[j + 1][i] = 0;
    }
    row = max_row;
}
void solve()
{
    while(true)
    {
        if(time > 100)
        {
            cout << -1;
            return;
        }
        if(r <= row && c <= col && A[r][c] == k)
        {
            cout << time;
            return;
        }

        if(row >= col)
            R();
        else
            C();
        time++;
    }
}
void input()
{
    cin >> r >> c >> k;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            cin >> A[i][j];
}
int main()
{
    input();
    solve();
    return 0;
}
