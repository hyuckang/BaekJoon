#include<iostream>
using namespace std;

int A[10];

void my_swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
void pr_arr()
{
    for(int i=0; i<5; i++)
        cout << A[i] << " ";
    cout << "\n";
}
int main()
{
    for(int i=0; i<5; i++)
        cin >> A[i];
    
    // bubble sort
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<4-i; j++)
        {
            if(A[j] > A[j + 1])
            {
                my_swap(A[j], A[j + 1]);
                pr_arr();
            }
        }
    }
    return 0;
}
