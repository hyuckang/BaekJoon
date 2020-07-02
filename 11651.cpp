#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
	vector<pair<int, int>> V;	// {y, x}
	
    cin >> N;
	for(int i=0; i<N; i++)
	{
		pair<int, int> location;
		cin >> location.second >> location.first;
		V.push_back(location);
	}
	
	sort(V.begin(), V.end());
	
	int V_sz = V.size();
	for(int i=0; i<N; i++)
		cout << V[i].second << " " << V[i].first << "\n";
	
	return 0;
}
