#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 1; i < n; i++){
            for (int j = 0; j < n; j++)
                A[i][j] += min({A[i-1][j],A[i-1][max(0,j-1)],A[i-1][min(j+1,n-1)]});
        }
        int r = A[n-1][0];
        for (int i = 1; i < n; i++)
            r = min(r,A[n-1][i]);

        return r;
    }
};



int main(){
    vector<vector<int>> a{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    cout << s.minFallingPathSum(a) << endl;

    return 0;
}
