#include <iostream>
#include <vector>
using namespace std;

int K;
int vist[10], nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char A[10];
long long max_res = -99999999999, min_res = 99999999999;
string max_str, min_str;

string to_string(vector<int> &V)
{
    string res;
    int V_sz = V.size();
    for(int i=0; i<V_sz; i++)
        res.push_back(V[i] + '0');
    return res;
}
long long to_longlong(vector<int> &V)
{
    long long res = 0, val = 1;
    int V_sz = V.size();
    for(int i=V_sz-1; i>-1; i--)
    {
        res += (V[i] * val);
        val *= 10;
    }
    return res;
}
bool vaild(vector<int> &V)
{
    for(int i=0; i<K; i++)
    {
        if(A[i] == '<')
        {
            if(V[i] > V[i + 1])
                return false;
        }
        else // '>'
        {
            if(V[i] < V[i + 1])
                return false;
        }
    }
    return true;
}
void go(int cnt, vector<int> &V)
{
    if(cnt == K + 1)
    {
        if(vaild(V))
        {
            long long res = to_longlong(V);
            string res_str = to_string(V);
            if(max_res < res)
                max_res = res, max_str = res_str;
            if(min_res > res)
                min_res = res, min_str = res_str;
        }
        return;
    }

    for(int i=0; i<10; i++)
    {
        if(!vist[i])
        {
            vist[i] = 1;
            V.push_back(i);
            go(cnt + 1, V);
            vist[i] = 0;
            V.pop_back();
        }
    }
}
int main()
{
    cin >> K;
    for(int i=0; i<K; i++)
        cin >> A[i];

    vector<int> V;
    go(0, V);

    cout << max_str << "\n" << min_str << "\n";
    return 0;
}
