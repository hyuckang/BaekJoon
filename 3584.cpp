#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, A, B, X, Y; 

int main()
{    
    cin >> T;
    while(T--)
    {
        cin >> N;       
        map<int, int> Tree; // [자식, 부모]
        for(int i=0; i<N-1; i++)
        {
            // A는 부모, B는 자식
            cin >> A >> B;
            Tree[B] = A;
        }
        
        cin >> X >> Y;
        // 현재 위치에서 루트노드까지 찾는다
        vector<int> X_parent = {X}, Y_parent = {Y};
        auto X_it = Tree.find(X), Y_it = Tree.find(Y);
        while(X_it != Tree.end())
        {
            X_parent.push_back(X_it->second);
            X_it = Tree.find(X_it->second);
        }
        while(Y_it != Tree.end())
        {
            Y_parent.push_back(Y_it->second);
            Y_it = Tree.find(Y_it->second);
        }

        // 현재 위치에서 루트노드까지 찾고 뒤집어서, 루트노드에서 현재위치까지 정렬한다
        reverse(X_parent.begin(), X_parent.end());
        reverse(Y_parent.begin(), Y_parent.end());

        int X_sz = X_parent.size(), Y_sz = Y_parent.size();
        if(X_sz < Y_sz)
        {
            for(int i=0; i<Y_sz-X_sz; i++)
                X_parent.push_back(-1);
        }
        else if(X_sz > Y_sz)
        {
            for(int i=0; i<X_sz-Y_sz; i++)
                Y_parent.push_back(-1);
        }

        for(size_t i=0; i<X_parent.size(); i++)
        {
            if(X_parent.at(i) != Y_parent.at(i))
            {
                cout << X_parent.at(i - 1) << "\n";
                break;
            }
        }
    }
    return 0;
}
