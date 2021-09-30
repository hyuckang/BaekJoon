#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K;
queue<int> Q;
vector<int> V;

int main()
{
	cin >> N >> K;
	for(int i=1; i<=N; i++)
		Q.push(i);
	
	while(!Q.empty())
	{
		int res = 1;
		while(res < K)
		{
			Q.push(Q.front());
			Q.pop();
			res++;
		}
		V.push_back(Q.front());
		Q.pop();
	}
	
	cout << "<";
	for(int i=0; i<N-1; i++)
		cout << V[i] << ", ";
	cout << V[N-1];
	cout << ">";
}
