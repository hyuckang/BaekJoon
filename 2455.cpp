#include<iostream>
using namespace std;

int main()
{
    int in, out, res = 0, max_res = -987654321;
    for(int i=0; i<4; i++)
    {
        cin >> out >> in;
        res = res - out + in;
        max_res = max(max_res, res);        
    }
    cout << max_res;
    return 0;
}
