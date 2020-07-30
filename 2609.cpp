#include<iostream>
using namespace std;

int my_gcd(int A, int B)
{
    if(B == 0)
        return A;
    else
        return my_gcd(B, A%B);
}
int my_lcm(int A, int B, int AB_gcd)
{
    return (A * B) / AB_gcd;
}
int main()
{
    int A, B;
    cin >> A >> B;
    
    int AB_gcd = my_gcd(A, B);
    int AB_lcm = my_lcm(A, B, AB_gcd);
    
    cout << AB_gcd << "\n" << AB_lcm << "\n";
}
