#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	
	int N;
	vector<pair<int, int>> A;
	
    cin >> N;
	for(int i=0; i<N; i++)
	{
		pair<int, int> location;
		cin >> location.first >> location.second;
		A.push_back(location);
	}
	
	sort(A.begin(), A.end());

	int A_sz = A.size();
	for(int i=0; i<A_sz; i++)
		cout << A[i].first << " " << A[i].second << "\n";
		
	return 0;
}
