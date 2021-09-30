#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string string_add(string A, string B)
{
    string long_str, short_str, carry = "0", res_str;
    if(A.size() > B.size())
        long_str = A, short_str = B;
    else
        long_str = B, short_str = A;
    
    reverse(long_str.begin(), long_str.end());
    reverse(short_str.begin(), short_str.end());

    int long_str_sz = long_str.size(), short_str_sz = short_str.size();

    // 자릿수 맞추기
    int digit_diff = long_str_sz - short_str_sz;
    for(int i=0; i<digit_diff; i++)
        short_str += '0';

    for(int i=0; i<long_str_sz; i++)
    {
        char digit_res = (long_str[i] + short_str[i]) - 48;
        if(digit_res > 57)
        {
            carry.push_back('1');
            res_str.push_back(digit_res - 10);
        }
        else
        {
            carry.push_back('0');
            res_str.push_back(digit_res);
        }

        // 올림 계산
        if(carry[i] == '1')
        {
            res_str[i]++;
            if(res_str[i] > 57)
            {
                res_str[i] -= 10;
                carry.pop_back();
                carry.push_back('1');
            }
        }
    }
    if(carry[long_str_sz] == '1')
        res_str.push_back('1');

    reverse(res_str.begin(), res_str.end());
    return res_str;
}

int main()
{
    string A, B;
    cin >> A >> B;
    cout << string_add(A, B);
}
