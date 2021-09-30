#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct NODE
{
    int in = 0, out = 0, semester = 0;
    vector<int> out_list;
};

int N, M;
NODE subject[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int a, b;
        cin >> a >> b;
        subject[a].out++;
        subject[a].out_list.push_back(b);
        subject[b].in++;
    }

    // cnt : 끝난 과목의 수, grade : 학기 계산
    int cnt = 0, grade = 1;
    while(cnt < N)
    {
        queue<NODE> Q;
        for(int idx=1; idx<=N; idx++)
        {
            // 아직 안끝난 과목이고, 진입차수가 0이라면
            if(subject[idx].semester == 0 && subject[idx].in == 0)
            {
                Q.push(subject[idx]);
                subject[idx].semester = grade;
                
                cnt++;
            }
        }

        while(!Q.empty())
        {
            NODE ended_subject = Q.front(); Q.pop();
            for(size_t i=0; i<ended_subject.out_list.size(); i++)
                subject[ended_subject.out_list.at(i)].in--;
        }
        grade++;
    }

    for(int idx=1; idx<=N; idx++)
        cout << subject[idx].semester << " ";

    return 0;
}
