#include<iostream>
#include<vector>
using namespace std;

int N, map[105][105];
int dr[] = {0, -1, 0, 1}, dc[] = {1, 0, -1, 0};

int change_dir(int dir)
{
    if(dir == 3)
        return 0;
    else
        return dir + 1;
}
int main()
{
    cin >> N;
    while(N--)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        
        // 0 세대
        vector<int> curve;
        curve.push_back(d);
        map[x][y] = 1;
        x += dc[d], y += dr[d];
        map[x][y] = 1;

        // 1세대 이상
        // 끝점을 기준으로 90도 회전하기 때문에
        // 이전 세대 커브의 '끝점부터 시작점까지 역순으로 회전'되어 추가가 된다.
        for(int gen=1; gen<=g; gen++)
        {
            int before_curve_sz = curve.size();

            for(int i=before_curve_sz-1; i>-1; i--)
            {
                int next_dir = change_dir(curve[i]);
                curve.push_back(next_dir);
                x += dc[next_dir], y += dr[next_dir];
                map[x][y] = 1;
            }
        }
    }

    // 정사각형 갯수 체크
    int res = 0;
    for(int r=0; r<100; r++)
    {
        for(int c=0; c<100; c++)
        {
            if(map[r][c] && map[r + 1][c] && map[r][c + 1] && map[r + 1][c + 1])
            {
                res++;
            }
        }
    }
    cout << res;
    return 0;
}
