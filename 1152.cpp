#include<iostream>
using namespace std;

int main()
{
    string input_str;
    getline(cin, input_str);

    int str_sz = input_str.size();
    if(str_sz == 1 && input_str[0] == ' ')
    {
        cout << 0;
        return 0;
    }

    int res = 0;
    for(int i=1; i<str_sz-1; i++)
    {
        if(input_str[i] == ' ') res++;
    }

    cout << res + 1;
    return 0;
}
