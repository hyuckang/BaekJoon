#include<iostream>
using namespace std;

int N, name_sz;
string file_name[55], pattern;

int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> file_name[i];
    
    name_sz = file_name[0].size();
    pattern = file_name[0];

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<name_sz; j++)
        {
            if(pattern[j] != file_name[i][j])
                pattern[j] = '?';
        }
    }

    cout << pattern << "\n";
}
