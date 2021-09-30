#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
	vector<int> V;
	
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int input_;
		cin >> input_;
		V.push_back(input_);
	}
	
	sort(V.begin(), V.end());
	
	int V_sz = V.size();
	for(int i=0; i<V_sz; i++)
		cout << V[i] << "\n";
	
	return 0;
}
