#include<iostream>
#include<set>
using namespace std;

int A, B;
set<int> S;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // in : 교집합의 개수, out : 교집합이 아닌 원소의 개수
    int in = 0, out = 0;
    cin >> A >> B;
    for(int i=0; i<A; i++)
    {
        int a;
        cin >> a;
        S.insert(a);
    }
    for(int i=0; i<B; i++)
    {
        int b;
        cin >> b;
        if(S.find(b) == S.end())
            out++;
        else
            in++;
    }
    cout << (A - in) + out;
}
