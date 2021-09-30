#include<iostream>
using namespace std;
int main()
{
    long long A, B, C, res;
    cin >> A >> B >> C;
    if(B >= C) res = -1;
    else
    {
        res = (A / (C - B)) + 1;
    }
    cout << res;    
    return 0;
}
