#include <iostream>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    if(A > B)
        swap(A, B); 

    int round = 1;
    while(true)
    {
        if(A % 2 == 1 && B % 2 == 0 && abs(A-B) == 1)
            break;
        
        if(A % 2 == 1)
            A = (A / 2) + 1;
        else
            A = A / 2;

        if(B % 2 == 1)
            B = (B / 2) + 1;
        else
            B = B / 2;

        round++;
    }
    cout << round;

    return 0;
}
