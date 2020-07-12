#include<iostream>
using namespace std;

int main()
{
    char tmp;
    int res = 0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin >> tmp;
            if(tmp == '.') continue;
            else if(i % 2 == 0 && j % 2 == 0) res++;
            else if(i % 2 == 1 && j % 2 == 1) res++;
        }
    }
    cout << res;
    return 0;
}
