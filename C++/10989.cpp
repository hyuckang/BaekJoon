/*
    Counting Sort
*/
#include<iostream>
using namespace std;

int N, A[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for(int i=0; i<N; i++)
    {
        int x;
        cin >> x;
        A[x]++;
    }

    for(int i=1; i<=10000; i++)
    {
        if(A[i])
        {
            for(int j=0; j<A[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }
    return 0;
}
