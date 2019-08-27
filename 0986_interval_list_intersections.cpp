#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> r;
        int i = 0, j = 0;
        int m = A.size(), n = B.size();
        while (i < m && j < n){
            while (i < m && A[i][1] < B[j][0])
                i++;
            if (i == m)
                break;
            while (j < n && B[j][1] < A[i][0])
                j++;
            if (j == n)
                break;
            int low = max(A[i][0], B[j][0]);
            int high = min(A[i][1], B[j][1]);
            if (low <= high)
                r.push_back({low,high});
            
            if (A[i][1] < B[j][1])
                i++;
            else
                j++;
        }

        return r;
    }
};



int main(){
    vector<vector<int>> A{{4,6}, {7,8}, {10,17}};
    vector<vector<int>> B{{5,10}};
    Solution s;
    vector<vector<int>> r = s.intervalIntersection(A, B);
    for (auto& i : r)
        cout << i[0] << "-" << i[1] << " ";
    cout << endl;

    return 0;
}
