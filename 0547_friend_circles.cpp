#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void util(vector<vector<int>>& M, int i){
        if (M[i][i] == -1) return;
        M[i][i] = -1;
        for (int k = 0; k < M.size(); k++){
            if (M[i][k] == 1)
                util(M, k);
        }
    }

    int findCircleNum(vector<vector<int>>& M) {
        int count = 0, n = M.size();
        for (int i = 0; i < n; i++){
            if (M[i][i] == 1){
                count++;
                util(M, i);
            }
        }

        return count;
    }
};



int main(){
    //vector<vector<int>> M {{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> M{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    Solution s;
    cout << s.findCircleNum(M) << endl;

    return 0;
}
