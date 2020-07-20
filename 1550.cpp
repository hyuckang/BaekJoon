#include<iostream>
using namespace std;

string A;
int res = 0;

int hexa_to_deci(int hexa)
{
    if(48 <= hexa && hexa <= 57)
        return hexa - '0';
    else
        return hexa - 55;
}
int main()
{
    cin >> A;
    int A_sz = A.size();
    int digit = 1;
    for(int i=A_sz-1; i>-1; i--)
    {
        res += hexa_to_deci(A[i]) * digit;
        digit *= 16;
    }
    cout << res;
    return 0;
}
