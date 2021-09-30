#include<iostream>
#include<set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N;
    set<string> S;
    string input_str;

    cin >> N;
    for(int i=1; i<2*N; i++)
    {
        cin >> input_str;
        if(S.find(input_str) == S.end())
            S.insert(input_str);
        else
            S.erase(input_str);
    }
    cout << *S.begin();
    
    return 0;
}
