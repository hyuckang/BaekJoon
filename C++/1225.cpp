#include<iostream>
using namespace std;

string A, B;
long long res = 0;
int main()
{   
    cin >> A >> B;
    int A_sz = A.size(), B_sz = B.size();
    for(int i=0; i<A_sz; i++)
    {
        for(int j=0; j<B_sz; j++)
        {
            res += (A[i] - '0') * (B[j] - '0');
        }
    }
    cout << res;
    return 0;
}
