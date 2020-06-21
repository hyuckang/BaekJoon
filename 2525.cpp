#include<iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int hour = C / 60;
    int min = C % 60;

    A += hour;
    B += min;
    if(B > 59)
    {
        B -= 60;
        A++;
    }
    if(A > 23) A -= 24;

    cout << A << " " << B;

    return 0;
}
