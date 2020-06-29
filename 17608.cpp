#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, res = 0, max_height;
    int h[100005];

    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> h[i];
    
    max_height = h[N];
    res++;
    for(int i=N-1; i>0; i--)
    {
        if(max_height < h[i])
        {
            max_height = h[i];
            res++;
        }
    }
    cout << res;
    return 0;
}
