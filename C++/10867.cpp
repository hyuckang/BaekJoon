#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
	set<int> S;
	vector<int> V;
	
	cin >> N;
	for(int i=0; i<N; i++)
	{
		int input_;
		cin >> input_;
		S.insert(input_);
	}
	
	for(set<int>::iterator S_itr = S.begin(); S_itr != S.end(); S_itr++)
		V.push_back(*S_itr);
	
	sort(V.begin(), V.end());
	
	int V_sz = V.size();
	for(int i=0; i<V_sz; i++)
		cout << V[i] << " ";
	
	return 0;
}
