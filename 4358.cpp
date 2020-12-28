#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cnt = 0;
    string name;
    map<string, int> TREE;
    
    while(getline(cin, name))
    {
        cnt++;
        
        if(TREE.find(name) == TREE.end())
            TREE[name] = 1;
        else
            TREE[name]++;
    }
    
    cout.precision(4);
    cout << fixed;
    for(auto X : TREE)
    {
        cout << X.first << " " << (X.second / (double)cnt) * 100 << "\n";
    }
    
    return 0;
}
