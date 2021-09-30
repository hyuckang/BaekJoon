#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N;
    vector<tuple<int, int, string>> A; // {나이, 가입순서, 이름}
    
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        A.push_back(make_tuple(age, i, name));
    }
    
    sort(A.begin(), A.end());

    int A_sz = A.size();
    for(int i=0; i<A_sz; i++)
    {
        int age, order;
        string name;
        tie(age, order, name) = A[i];
        
        cout << age << " " << name << "\n";
    }
	
	return 0;
}
