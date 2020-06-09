#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int N;

void solve()
{
    string name, log;
    set<string> S;
    vector<string> V;

    for(int i=0; i<N; i++)
    {
        cin >> name >> log;
        if(log == "enter") S.insert(name);
        else if("leave") S.erase(name);
    }

    for(set<string>::iterator S_iter = S.begin(); S_iter != S.end(); S_iter++)
    {
        V.push_back(*S_iter);
    }

    sort(V.begin(), V.end());

    int V_sz = V.size();
    for(int i=V_sz-1; i>-1; i--) cout<<V[i]<<"\n";
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
}
int main()
{
    input();
    solve();
    return 0;
}
