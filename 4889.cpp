#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int cnt = 1;
    while(true)
    {
        stack<char> ST;
        string str;
        int res = 0;

        cin >> str;
        if(str[0] == '-') break;

        if(str.size() != 0) 
        {
            for(auto X : str)
            {
                if(X == '{')
                    ST.push('{');
                else
                {
                    // 스택이 비어있는데 닫는 괄호가 들어온다면 바꿔야한다.
                    // 바꿔서 스택에 넣어준다.
                    if(ST.size() == 0)
                    {
                        res++;
                        ST.push('{');
                    }
                    else
                        ST.pop();
                }
            }
        }

        // 결국 스택에는 {{, {{{, {{{{ 만이 남는다.
        // 이를 올바르게 바꾸기 위해서는 절반을 바꿔주면 된다.
        res += ST.size() / 2;

        cout << cnt++ << ". " << res << "\n";
    }
    return 0;
}
