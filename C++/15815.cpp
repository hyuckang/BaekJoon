#include<iostream>
#include<stack>
using namespace std;

int main()
{
    string input_str;
    cin >> input_str;
    
    stack<int> ST;
    int str_sz = input_str.size();

    for(int i=0; i<str_sz; i++)
    {
        if(input_str[i] == '+')
        {
            int a = ST.top(); ST.pop();
            int b = ST.top(); ST.pop();
            ST.push(b + a);
        }
        else if(input_str[i] == '-')
        {
            int a = ST.top(); ST.pop();
            int b = ST.top(); ST.pop();
            ST.push(b - a);
        }
        else if(input_str[i] == '*')
        {
            int a = ST.top(); ST.pop();
            int b = ST.top(); ST.pop();
            ST.push(b * a);
        }
        else if(input_str[i] == '/')
        {
            int a = ST.top(); ST.pop();
            int b = ST.top(); ST.pop();
            ST.push(b / a);
        }
        else
            ST.push(input_str[i] - '0');
    }
    cout << ST.top();
    return 0;
}
