#include <bits/stdc++.h>
using namespace std;

int N;
char P, L, R;
map<char, pair<char, char>> TREE;

void PRE_ORDER(char cur)
{
    // 루트 -> 왼쪽 -> 오른쪽
    cout << cur;
    if(TREE[cur].first != '.')
        PRE_ORDER(TREE[cur].first);
    if(TREE[cur].second != '.')
        PRE_ORDER(TREE[cur].second);
}
void IN_ORDER(char cur)
{
    // 왼쪽 -> 루트 -> 오른쪽
    if(TREE[cur].first != '.')
        IN_ORDER(TREE[cur].first);
    
    cout << cur;

    if(TREE[cur].second != '.')
        IN_ORDER(TREE[cur].second);
}
void POST_ORDER(char cur)
{
    // 왼쪽 -> 오른쪽 -> 루트
    if(TREE[cur].first != '.')
        POST_ORDER(TREE[cur].first);
    
    if(TREE[cur].second != '.')
        POST_ORDER(TREE[cur].second);
    
    cout << cur;
}
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> P >> L >> R;
        TREE[P] = {L, R};
    }

    PRE_ORDER('A');
    cout << "\n";

    IN_ORDER('A');
    cout << "\n";
    
    POST_ORDER('A');
    cout << "\n";

    return 0;
}
