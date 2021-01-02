/*
    end_board 라는 set에 가능한 모든 종료된 판을 넣어둔다.
*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int per[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

bool check(string board, char stone)
{
    // row
    for(int i=0; i<3; i++)
        if(board[0 + i * 3] == stone && board[1 + i * 3] == stone && board[2 + i * 3] == stone) return true;

    // col
    for(int i=0; i<3; i++)
        if(board[0 + i] == stone && board[3 + i] == stone && board[6 + i] == stone) return true;

    // dia
    if(board[0] == stone && board[4] == stone && board[8] == stone) return true;
    if(board[2] == stone && board[4] == stone && board[6] == stone) return true;

    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    set<string> end_board;

    do
    {
        string board = ".........";

        for(int i=0; i<9; i++)
        {
            char stone;
            if(i % 2 == 0) stone = 'X';
            else stone = 'O';

            board[per[i]] = stone;
            if(check(board, stone))
            {
                end_board.insert(board);
                break;
            }
        }
        end_board.insert(board);

    } while(next_permutation(per, per + 9));

    while(true)
    {
        string input_board;
        cin >> input_board;

        if(input_board == "end") break;

        if(end_board.find(input_board) == end_board.end())
            cout << "invalid\n";
        else
            cout << "valid\n";
    }

    return 0;
}
