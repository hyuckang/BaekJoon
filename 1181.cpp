#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string &X, string &Y)
{
    // X가 더 짧다면 -> true, 이미 정렬된 상태이므로 
    if(X.size() < Y.size())
        return true;
    // Y가 더 짧다면 -> false, 정렬해아함
    else if(X.size() > Y.size())
        return false;
    // X.size() == Y.size() -> 사전순으로
    else
        return X < Y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
    set<string> S;  // 중복제거
	vector<string> V;
	
	cin >> N;
	for(int i=0; i<N; i++)
	{
		string input_;
		cin >> input_;
		S.insert(input_);
	}
	
    for(set<string>::iterator S_itr = S.begin(); S_itr != S.end(); S_itr++)
        V.push_back(*S_itr);

	sort(V.begin(), V.end(), cmp);
	
	int V_sz = V.size();
	for(int i=0; i<V_sz; i++)
		cout << V[i] << "\n";
	
	return 0;
}
