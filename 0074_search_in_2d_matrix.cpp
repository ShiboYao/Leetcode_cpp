#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        int left = 0, right = m*n - 1;
        while (left <= right){
            int mid = (left+right)/2;
            int i = mid/n, j = mid%n;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                right = mid-1;
            else
                left = mid+1;
        }

        return false;
    }
};



int main(){
    vector<vector<int>> a{{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
    int target = 3;
    Solution s;
    cout << s.searchMatrix(a, target) << endl;

    return 0;
}
