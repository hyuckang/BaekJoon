#include<iostream>
#include<stack>
using namespace std;

bool solve(string str)
{
    stack<char> S;
    int str_sz = str.size();
    for(int i=0; i<str_sz; i++)
    {
        if(str[i] == '[' || str[i] == '(')
            S.push(str[i]);
        else if(str[i] == ']' || str[i] == ')')
        {
            if(S.empty()) return false;
            
            char cmp_val;
            if(str[i] == ']') cmp_val = '[';
            else cmp_val = '(';
            
            if(S.top() == cmp_val) S.pop();
            else return false;
        }
    }   
    if(S.empty()) return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while(true)
    {
        string input_str;
        getline(cin, input_str);
        if(input_str[0] == '.') break;
        if(solve(input_str))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
