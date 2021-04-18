#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, x, y, res = 0;
    vector<pair<int, int>> pointer;

    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> x >> y;
        pointer.push_back({x, y});
    }

    sort(pointer.begin(), pointer.end());

    int L = pointer[0].first, R = pointer[0].second;

    for(int i=1; i<N; i++)
    {
        x = pointer[i].first, y = pointer[i].second;

        if(y <= R) // 기존 구간에 포함
        {   
            continue;
        }
        else if(x <= R && R < y) // 오른쪽 구간 증가
        {
            R = y;
        }
        else // R < x , 새로운 구간 증가
        {
            res += (R - L);
            L = x, R = y;
        }
    }
    res += (R - L);

    cout << res << "\n";

    return 0;
}
