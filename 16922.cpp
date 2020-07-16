#include<iostream>
using namespace std;

int N, res = 0;
int vist[1005], roma[] = {1, 5, 10, 50};

void go(int cnt, int sum, int start)
{
    if(cnt == N)
    {
        if(vist[sum] == 0)
        {
            vist[sum] = 1;
            res++;
        }
        return;
    }

    for(int i=start; i<4; i++)
        go(cnt + 1, sum + roma[i], i);
}
int main()
{
    cin >> N;

    go(0, 0, 0);
    cout << res;
    return 0;
}
