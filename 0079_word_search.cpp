#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool util(vector<vector<char>>& board, int i, int j, int k, vector<vector<bool>>& visited, string& word){
        if (i == board.size() || i < 0 || j == board[0].size() || j < 0)
            return false;
        if (!visited[i][j] && board[i][j] == word[k]){
            visited[i][j] = true;
            if (k+1 == word.size())
                return true;
            if (util(board,i+1,j,k+1,visited,word)) return true;
            else if (util(board,i-1,j,k+1,visited,word)) return true;
            else if (util(board,i,j+1,k+1,visited,word)) return true;
            else if (util(board,i,j-1,k+1,visited,word)) return true;
            else {
                visited[i][j] = false;
                if (k == 0)
                    return false;
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word){
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        vector<vector<bool>> visited{vector<bool>(n,false)};
        for (int i = 1; i < m; i++)
            visited.push_back(visited[0]);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0] && util(board,i,j,0,visited,word))
                    return true;
            }
        }

        return false;
    }
};


/*
class Solution {
public:
    bool util(vector<vector<char>>& board, vector<int> loc, vector<vector<int>>& visited, string& word){
        if (loc[0] == board.size() || loc[0] < 0 || loc[1] == board[0].size() || loc[1] < 0)
            return false;
        if (find(visited.begin(), visited.end(), loc) == visited.end() && board[loc[0]][loc[1]] == word[visited.size()]){
            visited.push_back(loc);
            if (visited.size() == word.size())
                return true;
            if (util(board, {loc[0]+1,loc[1]}, visited, word)) 
                return true;
            else if (util(board, {loc[0]-1,loc[1]}, visited, word)) 
                return true;
            else if (util(board, {loc[0],loc[1]+1}, visited, word)) 
                return true;
            else if (util(board, {loc[0],loc[1]-1}, visited, word)) 
                return true;
            else{
                visited.pop_back();
                if (visited.empty())
                    return false;
            }
        }

        return false;
    }       

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0)
            return false;
        int n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0]){
                    vector<vector<int>> visited;
                    if (util(board, {i,j}, visited, word))
                        return true;
                }
            }
        }

        return false;
    }
};
*/


int main(){
    vector<vector<char>> a{{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    //string word = "SEE";
    //string word = "ABCB";
    Solution s;
    cout << s.exist(a, word) << endl;

    return 0;
}
