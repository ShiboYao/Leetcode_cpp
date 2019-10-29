#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void change(vector<vector<int>>& board, int x, int y){
        int sum = 0, m = board.size(), n = board[0].size();
        if (y > 0){
            sum += board[y-1][x] > 0;
            if (x > 0)
                sum += board[y-1][x-1] > 0;
            if (x < n-1)
                sum += board[y-1][x+1] > 0;
        }
        if (y < m-1){
            sum += board[y+1][x] > 0;
            if (x > 0)
                sum += board[y+1][x-1] > 0;
            if (x < n-1)
                sum += board[y+1][x+1] > 0;
        }
        if (x > 0)
            sum += board[y][x-1] > 0;
        if (x < n-1)
            sum += board[y][x+1] > 0;
        if (board[y][x] > 0 && (sum < 2 || sum > 3))
            board[y][x] = 2;
        else if (board[y][x] == 0 && sum == 3)
            board[y][x] = -1;
    }


    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++)
                change(board, j, i);
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == -1)
                    board[i][j] = 1;
                else if (board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};



int main(){
    vector<vector<int>> a{{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    Solution s;
    s.gameOfLife(a);
    for (vector<int>& i : a){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
