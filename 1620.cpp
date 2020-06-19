#include<iostream>
#include<map>
#include<string>
using namespace std;

int N, M;
string pockemon[100005];        // 숫자를 물어볼때
map<string, int> pocketmon_map; // 이름을 물어볼때

bool is_num(string str)
{
    // ASCI : '0'(48) ~ '9'(57)
    bool flag = true;
    int str_sz = str.size();
    for(int i=0; i<str_sz; i++)
    {
        if(48 > str[i] || str[i] > 57) flag = false;            
    }
    return flag;
}
void solve()
{
    string query;
    for(int i=1; i<=M; i++)
    {
        cin >> query;
        if(is_num(query))
            cout << pockemon[stoi(query)] << "\n";
        else
            cout << pocketmon_map[query] << "\n";
    }
}
void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        cin >> pockemon[i];
        pocketmon_map.insert(make_pair(pockemon[i], i));
    }
}
int main()
{
    input();
    solve();
    return 0;
}
