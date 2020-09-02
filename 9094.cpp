#include <iostream>
using namespace std;

int T, n, m;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        int res = 0;
        for(int a=1; a<n; a++)
        {
            for(int b=a+1; b<n; b++)
            {
                if((a*a + b*b + m) % (a * b) == 0)
                    res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}
