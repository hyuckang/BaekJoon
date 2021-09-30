#include<iostream>
#include<vector>
using namespace std;
int N, B, C;
long long cnt1, cnt2; // 총감독수, 부감독수, 각 방마다 100만명이 있을수 있으므로 오버플로우가 일어날수 있기 때문에 long long으로 선언해주어야한다.
vector<int> A;
void input()
{
    cin>>N;
    int tmp;
    for(int i=0; i<N; i++)
    {
        cin>>tmp;
        A.push_back(tmp);
    }
    cin>>B>>C;
}
void solve()
{
    int num;
    for(int i=0; i<N; i++)
    {
        num = A[i];
        num = num - B;
        cnt1++;
        // 총감독 1명을 배치한 후에 남은 인원이 -가 될 수있으므로
        // 남은 인원이 0을 초과 할 때 부감독을 배치해야한다
        if(num > 0)
        {
            if(num%C != 0)
            {
                cnt2 = cnt2 + num/C + 1;
            }
            else
            {
                cnt2 = cnt2 + num/C;
            }
        }
    }
    cout<<cnt1 + cnt2<<"\n";
}
int main()
{
    input();
    solve();
}
