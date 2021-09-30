#include<iostream>
using namespace std;
int main()
{
    pair<int, int> v[3];
    int x, y;
    for(int i=0; i<3; i++)
        cin >> v[i].first >> v[i].second;
    if(v[1].first == v[2].first)
        x = v[0].first;
    else if(v[0].first == v[2].first)
        x = v[1].first;
    else
        x = v[2].first;
        
    if(v[1].second == v[2].second)
        y = v[0].second;
    else if(v[0].second == v[2].second)
        y = v[1].second;
    else
        y = v[2].second;

    cout << x << " " << y;

    return 0;
}
