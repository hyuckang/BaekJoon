#include<iostream>
using namespace std;

int main()
{
    int A[26] = {0, };    
    string input_str;
    cin >> input_str;
    
    int str_sz = input_str.length();
    for(int i=0; i<str_sz; i++) A[input_str[i] - 'a']++;
    for(int i=0; i<26; i++) cout << A[i] << " ";

    return 0;
}
