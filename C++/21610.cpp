#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M, result;
int dr[] = {0,  0, -1, -1, -1, 0, 1, 1,  1};
int dc[] = {0, -1, -1,  0,  1, 1, 1, 0, -1};
int xr[] = {-1, -1, 1, 1}, xc[] = {-1, 1, -1, 1};
int A[55][55], d[105], s[105];

int main()
{
    // input
    cin >> N >> M;
    for (int r=1; r<=N; r++)
        for (int c=1; c<=N; c++)
            cin >> A[r][c];
    
    for (int i=0; i<M; i++)
        cin >> d[i] >> s[i];

    // solve
    vector<pair<int, int>> Cloud = {{N - 1, 1}, {N - 1, 2}, {N, 1}, {N, 2}};

    for (int X=0; X<M; X++)
    {

        // [1]
        for (size_t i=0; i<Cloud.size(); i++)
        {
            s[X] = s[X] % N;

            int nr = Cloud[i].first + (dr[d[X]] * s[X]);
            int nc = Cloud[i].second + (dc[d[X]] * s[X]);
            
            if (nr < 0)
                nr = N - (nr * -1);
            else if (nr == 0)
                nr = N;
            else if (nr > N)
                nr = nr % N;

            if (nc < 0)
                nc = N - (nc * -1);
            else if (nc == 0)
                nc = N;
            else if (nc > N)
                nc = nc % N;
            
            Cloud[i].first = nr, Cloud[i].second = nc;
        }

        set<pair<int, int>> Cloud_set;
        for (auto C : Cloud)
        {
            // [2]
            A[C.first][C.second] += 1;
            Cloud_set.insert({C.first, C.second});
        }

        // [4]
        for (auto C : Cloud)
        {
            int count = 0;
            for (int dir=0; dir<4; dir++)
            {
                int nr = C.first + xr[dir];
                int nc = C.second + xc[dir];
                if (nr <= 0 || nr > N || nc <= 0 || nc > N) continue;
                if (A[nr][nc] > 0)
                    count++;
            }
            A[C.first][C.second] += count;
        }
            
        // [3]
        Cloud.clear();

        // [5]
        for (int r=1; r<=N; r++)
        {
            for (int c=1; c<=N; c++)
            {
                if (A[r][c] >= 2 && Cloud_set.find({r, c}) == Cloud_set.end())
                {
                    A[r][c] -= 2;
                    Cloud.push_back({r, c});
                }
            }
        }
    }


    for (int r=1; r<=N; r++)
        for (int c=1; c<=N; c++)
            result += A[r][c];

    cout << result;

    return 0;
}
