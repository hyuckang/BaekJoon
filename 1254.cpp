#include <iostream>
using namespace std;

bool check_palindrome(string str)
{
    for(size_t i=0; i<str.size()/2; i++)
    {
        if(str[i] != str[str.size() - i - 1]) return false;
    }
    return true;
}
int main()
{
    string str;
    cin >> str;

    // idx가 뒤로가면서 팰린드롬을 찾으면, 그 앞에 문자수만큼 뒤에 붙여주면 팰린드롬이 된다.
    for(size_t idx=0; idx<str.size(); idx++)
    {
        if(check_palindrome(str.substr(idx, str.size() - idx)))
        {
            cout << str.size() + idx;
            break;
        }
    }

    return 0;
}
