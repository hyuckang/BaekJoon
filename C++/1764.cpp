#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
set<string> S;
vector<string> V;

int main()
{
    cin >> N >> M;
    string name;
    for(int i=0; i<N; i++)
    {
        cin >> name;
        S.insert(name);
    }
    for(int i=0; i<M; i++)
    {
        cin >> name;
        if(S.find(name) != S.end()) V.push_back(name);
    }

    sort(V.begin(), V.end());

    int V_sz = V.size();
    cout<<V_sz<<"\n";
    for(int i=0; i<V_sz; i++) cout<<V[i]<<"\n";

    return 0;
}
