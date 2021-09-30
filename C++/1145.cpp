#include <iostream>
using namespace std;

int nums[5];
long long multiple = 2;

int main()
{
    for(int i=0; i<5; i++)
        cin >> nums[i];

    while(true)
    {
        int cnt = 0;
        for(int i=0; i<5; i++)
        {
            if(multiple % nums[i] == 0)
                cnt++;
        }

        if(cnt >= 3)
            break;

        multiple++;
    }

    cout << multiple;
    
    return 0;
}
