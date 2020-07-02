#include<iostream>
using namespace std;

// time[i][a] : a번 차가 i분에 존재하였음을 의미
// 첫번째 입력이 1 6 이라면 -> time[1][0] ~ time[5][0] 까지 1의 값을 가짐
// 1분에 정확히 나가고, 6분에 정확히 나가기 때문에
// 1~2, 2~3, 3~4, 4~5, 5~6를 의미 
int A, B, C, res, time[105][3];
int main()
{
	cin >> A >> B >> C;
	for(int i=0; i<3; i++)
	{
		int st, en;
		cin >> st >> en;
		for(int j=st; j<en; j++)
		{	
			time[j][i] = 1;
		}
	}

	for(int i=1; i<=100; i++)
    {
        int cars = time[i][0] + time[i][1] + time[i][2];
        if(cars == 3)
            cars *= C;
        else if(cars == 2)
            cars *= B;
        else if(cars == 1)
            cars *= A;
        res += cars;
    }
	
    cout << res;
}
