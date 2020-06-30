#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
	int K;
	cin >> K;
	
	int res = 0;
	vector<int> V;
	for(int i=0; i<K; i++)
	{
		int input_tmp;
		cin >> input_tmp;
        
		if(input_tmp != 0)
		{
			V.push_back(input_tmp);
			res += input_tmp;
		}
		else
		{
            res -= V[V.size() - 1];
            V.pop_back();
		}
	}
	
	cout << res;
	
	return 0;
}
