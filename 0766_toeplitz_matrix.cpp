#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int k = 0; k < n; k++){
            for (int i = 1; i < m && k+i < n; i++)
                if (matrix[i][k+i] != matrix[i-1][k+i-1]) return false;
        }
        for (int k = 1; k < m; k++){
            for (int i = 1; k+i < m && i < n; i++)
                if (matrix[k+i][i] != matrix[k+i-1][i-1]) return false;
        }

        return true;
    }
};



int main(){
    //vector<vector<int>> a{{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    vector<vector<int>> a{{1,2},{2,2}};
    Solution s;
    cout << s.isToeplitzMatrix(a) << endl;

    return 0;
}
