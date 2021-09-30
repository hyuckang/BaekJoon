#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        vector<string> PK1, PK2, crypt_str;
        vector<int> A;  // 복호화 순서

        string input_str;
        for(int i=0; i<N; i++)
        {
            cin >> input_str;
            PK1.push_back(input_str);
        }
        for(int i=0; i<N; i++)
        {
            cin >> input_str;
            PK2.push_back(input_str);
        }
        for(int i=0; i<N; i++)
        {
            cin >> input_str;
            crypt_str.push_back(input_str);
        }

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(PK1[i] == PK2[j])
                    A.push_back(j);
            }
        }

        for(int i=0; i<N; i++)
        {
            cout << crypt_str[A[i]] << " ";
        }
        cout<<"\n";
    }    
    return 0;
}
