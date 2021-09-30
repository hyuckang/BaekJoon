#include <bits/stdc++.h>
using namespace std;

int N, P, L, R, ROOT, MAX_height, MAX_WIDTH, LEVEL;
map<int, int> PARENT, ROW;
map<int, pair<int, int>> TREE;
vector<int> COL;

void Travel(int cur)
{
    if(TREE[cur].first != -1)
    {
        ROW[TREE[cur].first] = ROW[cur] + 1;
        MAX_height = max(MAX_height, ROW[TREE[cur].first]);
        Travel(TREE[cur].first);
    }

    COL.push_back(cur);

    if(TREE[cur].second != -1)
    {
        ROW[TREE[cur].second] = ROW[cur] + 1;
        MAX_height = max(MAX_height, ROW[TREE[cur].first]);
        Travel(TREE[cur].second);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // input & init
    cin >> N;
    for(int i=1; i<=N; i++)
        PARENT[i] = 0;
    
    for(int i=0; i<N; i++)
    {
        cin >> P >> L >> R;
        TREE[P] = {L, R};
        if(L != -1) PARENT[L] = P;
        if(R != -1) PARENT[R] = P;
    }

    // find ROOT
    for(auto it : PARENT)
        if(it.second == 0)
            ROOT = it.first;

    // Travel, ROW
    ROW[ROOT] = 1;
    MAX_height = 1, MAX_WIDTH = 1, LEVEL = 1;
    Travel(ROOT);

    // COL
    for(int height=2; height<=MAX_height; height++)
    {
        int COL_L, COL_R;
        for(int i=0; i<(int)COL.size(); i++)
        {
            if(ROW[COL[i]] == height)
            {
                COL_L = i;
                break;
            }
        }
        for(int i=(int)COL.size()-1; 0<=i; i--)
        {
            if(ROW[COL[i]] == height)
            {
                COL_R = i;
                break;
            }
        }

        int WIDTH = COL_R - COL_L + 1;
        if(MAX_WIDTH < WIDTH)
            MAX_WIDTH = WIDTH, LEVEL = height;
    }

    cout << LEVEL << " " << MAX_WIDTH << "\n";

    return 0;
}