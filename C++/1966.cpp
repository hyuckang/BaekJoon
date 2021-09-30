#include<iostream>
#include<queue>
using namespace std;

int T, N, M;
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		
		// {priority, idx}
		queue<pair<int, int>> Q;
		priority_queue<int> PQ;
		for(int i=0; i<N; i++)
		{
			int p;
			cin >> p;
			Q.push(make_pair(p, i));
			PQ.push(p);
		}
		
		int res = 0;
		while(!Q.empty())
		{
			pair<int, int> cur_job = Q.front(); Q.pop();
			int max_priority = PQ.top(); PQ.pop();
			if(cur_job.first == max_priority)
			{
				res++;
				if(cur_job.second == M) break;
			}
			else if(cur_job.first < max_priority)
			{
				Q.push(cur_job);
				PQ.push(max_priority);
			}
		}
		cout << res << "\n";
	}
	return 0;
}
