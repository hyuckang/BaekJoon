#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, x1, y1, r1, x2, y2, r2;

    cin >> T;
    while(T--)
    {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = ((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1));
        int r_sum = (r1 + r2) * (r1 + r2), r_sub = (r1 - r2) * (r1 - r2);

        if(dist == 0)
        {
            if(r_sub == 0)
                cout << -1 << "\n";
            else
                cout << 0 << "\n";
        }
        else
        {
            if(dist == r_sum || dist == r_sub)
                cout << 1 << "\n";
            else if(r_sub < dist && dist < r_sum)
                cout << 2 << "\n";
            else if(dist > r_sum || dist < r_sub)
                cout << 0 << "\n";
        }
    }
}
