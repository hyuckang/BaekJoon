#include <iostream>
using namespace std;

int W_sz, S_sz, W_alpha[55], S_alpha[55], res;
string W, S;

bool check()
{
    for(int i=0; i<52; i++)
    {
        if(W_alpha[i] != S_alpha[i]) return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> W_sz >> S_sz >> W >> S;

    for(auto ch : W)
    {
        if('a' <= ch)
            W_alpha[ch - 'a' + 26]++;
        else
            W_alpha[ch - 'A']++;
    }
    
    // 슬라이딩 윈도우 만들기
    for(int i=0; i<W_sz; i++)
    {
        char ch = S[i];
        if('a' <= ch)
            S_alpha[ch - 'a' + 26]++;
        else
            S_alpha[ch - 'A']++;
    }
    if(check()) res++;

    for(int i=1; i<=S_sz-W_sz; i++)
    {
        // 전에 칸 지우기
        char before_ch = S[i - 1], next_ch = S[i + W_sz - 1];
        
        if('a' <= before_ch)
            S_alpha[before_ch - 'a' + 26]--;
        else
            S_alpha[before_ch - 'A']--;
        
        // 뒤에 칸 추가하기
        if('a' <= next_ch)
            S_alpha[next_ch - 'a' + 26]++;
        else
            S_alpha[next_ch - 'A']++;

        if(check()) res++;
    }
    
    cout << res << "\n";

    return 0;
}
