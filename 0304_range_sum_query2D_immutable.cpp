#include <iostream>
#include <vector>
using namespace std;


class NumMatrix {
public:
    vector<vector<int>> a;
    int m = 0;
    int n = 0;
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m) {
            n = matrix[0].size();
            a = vector<vector<int>> (m+1, vector<int>(n+1));
            for (int i = 0; i < m; i++){
                for (int j = 0; j < n; j++)
                    a[i+1][j+1] = a[i+1][j] + matrix[i][j];
            }
            for (int i = 1; i < m; i++){
                for (int j = 0; j < n; j++)
                    a[i+1][j+1] += a[i][j+1];
            }
        }
    }   

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0)
            return 0;
        return a[row2+1][col2+1]-a[row2+1][col1]-a[row1][col2+1]+a[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */



 int main(){
    vector<vector<int>> matrix{{3,0,1,4,2},
                                {5,6,3,2,1},
                                {1,2,0,1,5},
                                {4,1,0,1,7},
                                {1,0,3,0,5}};
    NumMatrix* obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2,1,4,3) << endl;

    return 0;
 }
