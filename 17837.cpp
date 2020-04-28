#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;
struct HORSE
{
    int r, c, dir;
};
int N, K, turn_res = 0;
int map[15][15];
int dr[] = {0, 0, 0 , -1, 1}, dc[] = {0, 1, -1, 0, 0};
vector<int> H_map[15][15];
HORSE H[15];

void pr_map()
{
    cout<<"=== map ===\n";
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cout<<H_map[i][j].size()<<" ";
        }
        cout<<"\n";
    }
}
void pr_h_idx()
{
    cout<<"+++++++++++++++++\n";
    for(int i=1; i<=K; i++)
    {
        cout<<H[i].r<<", "<<H[i].c<<", "<<H[i].dir<<"\n";
    }
    cout<<"+++++++++++++++++\n";
}



int change_dir(int dir)
{
    if(dir == 1) return 2;
    else if(dir == 2) return 1;
    else if(dir == 3) return 4;
    else return 3;
}
int find_h_idx(int idx, int r, int c)
{   
    // idx 번째 말이 h_map[r][c]에서 몇번째에 위치했는지를 retrun
    int H_idx;
    int H_map_sz = H_map[r][c].size();
    for(int i=0; i<H_map_sz; i++)
    {
        if(idx == H_map[r][c].at(i))
        {
            H_idx = i;
            break;
        }
    }
    return H_idx;
}

void move_horse(int idx)
{

    // cout<<idx<<" horse\n";
    // cout<<"cur_r : "<<H[idx].r<<", cur_c : "<<H[idx].c<<"\n";

    int cur_r = H[idx].r, cur_c = H[idx].c, cur_dir = H[idx].dir;
    int nr = cur_r + dr[cur_dir];
    int nc = cur_c + dc[cur_dir];

    // 맵을 벗어남
    if(nr <= 0 || nr > N || nc <= 0 || nc > N)
    {
        // nr, nc가 맵을 벗어남(파란색임) -> 방향바꿈
        H[idx].dir = change_dir(cur_dir);
        cur_dir = H[idx].dir;

        int nnr = cur_r + dr[cur_dir];
        int nnc = cur_c + dc[cur_dir];
        // nnr, nnc 도 맵을 벗어남 -> 파란색임 return
        if(nnr <= 0 || nnr > N || nnc <= 0 || nnc > N) return;
        // nnr, nnc 가 파란색임 -> return
        if(map[nnr][nnc] == 2) return;
        // nnr, nnc가 흰색이거나 빨간색임 -> move_horse
        else move_horse(idx);
    }

    // idx 번째 말 위의 말들과 함께 움직이기 위함
    int H_idx = find_h_idx(idx, cur_r, cur_c);
    int H_map_sz = H_map[cur_r][cur_c].size();
    
    // 흰색
    if(map[nr][nc] == 0)
    {
        stack<int> S;
        for(int i=H_map_sz-1; i>=H_idx; i--)
        {
            int horse_idx = H_map[cur_r][cur_c].at(i);
            S.push(horse_idx);
            
            H[horse_idx].r = nr, H[horse_idx].c = nc;
            H_map[cur_r][cur_c].pop_back();
        }
        while(!S.empty())
        {
            H_map[nr][nc].push_back(S.top());
            S.pop();
        }
    }
    // 빨간색
    else if(map[nr][nc] == 1)
    {
        queue<int> Q;
        for(int i=H_map_sz-1; i>=H_idx; i--)
        {
            int horse_idx = H_map[cur_r][cur_c].at(i);
            Q.push(horse_idx);

            H[horse_idx].r = nr, H[horse_idx].c = nc;
            H_map[cur_r][cur_c].pop_back();
        }
        while(!Q.empty())
        {
            H_map[nr][nc].push_back(Q.front());
            Q.pop();
        }
    }
    // 파란색
    else
    {
        // map[nr][nc]가 파란색임 -> 방향바꿈
        H[idx].dir = change_dir(cur_dir);
        cur_dir = H[idx].dir;

        int nnr = cur_r + dr[cur_dir];
        int nnc = cur_c + dc[cur_dir];
        // nnr, nnc 가 맵을 벗어남(파란색임) -> return
        if(nnr <= 0 || nnr > N || nnc <= 0 || nnc > N) return;
        // map[nnr][nnc] 가 파란색임 -> return
        if(map[nnr][nnc] == 2) return;
        // nnr, nnc가 흰색이거나 빨간색임 -> move_horse
        else move_horse(idx);
    }
    
    return;
}
void solve()
{
    while(true)
    {
        // 말 이동
        // cout<<"+_+_+_+_+_+_+_+_+_+_+\n";
        turn_res++;

        for(int k=1; k<=K; k++)
        {
            move_horse(k);
            for(int h_idx=1; h_idx<=K; h_idx++)
            {
                int h_r = H[h_idx].r, h_c = H[h_idx].c;
                if(H_map[h_r][h_c].size() >= 4)
                {
                    cout<<turn_res;
                    return;
                }
            }
            // pr_h_idx();
            // pr_map();
        }
        // cout<<"+_+_+_+_+_+_+_+_+_+_+\n";
        
        // getchar();
        // getchar();
        // getchar();

        // 턴 증가
        // turn_res++;

        // 종료검사
        if(turn_res > 1000)
        {
            cout<<-1;
            return;
        }
        /*
        for(int idx=1; idx<=K; idx++)
        {
            int h_r = H[idx].r, h_c = H[idx].c;
            if(H_map[h_r][h_c].size() >= 4)
            {
                cout<<turn_res;
                return;
            }
        }
        */
    }

}
void input()
{
    cin>>N>>K;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            cin>>map[i][j];
        }
    }
    for(int i=1; i<=K; i++)
    {
        cin>>H[i].r>>H[i].c>>H[i].dir;
        H_map[H[i].r][H[i].c].push_back(i);
    }
}
int main()
{
    input();
    // pr_map();
    solve();
    return 0;
}
