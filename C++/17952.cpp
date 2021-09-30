#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int N, cmd, A, T, res = 0;
    deque<pair<int, int>> DQ;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> cmd;
        if(cmd == 1)
        {
            cin >> A >> T;
            T--;
            if(T == 0)
                res += A;
            else
                DQ.push_front({A, T});
        }
        else
        {
            pair<int, int> cur_task = DQ.front(); DQ.pop_front();
            cur_task.second--;
            if(cur_task.second == 0)
                res += cur_task.first;
            else
                DQ.push_front(cur_task);
        }
    }
    cout << res;

    return 0;
}
