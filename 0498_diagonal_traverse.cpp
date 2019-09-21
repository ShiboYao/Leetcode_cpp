#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        int m = matrix.size();
        if (m == 0) return r;
        int n = matrix[0].size();
        int i = 0, j = 0, count = m*n;
        while(true){
            while (i >= 0 && j < n)
                r.push_back(matrix[i--][j++]);
            if (r.size() == count)
                break;
            if (j == n) {
                j--;
                i += 2;
            }
            else if (i < 0)
                i++;
            while (i < m && j >= 0)
                r.push_back(matrix[i++][j--]);
            if (r.size() == count)
                break;
            if (i == m){
                i--;
                j += 2;
            }
            else if (j < 0)
                j++;
        }
        
        return r;
    }
};



int main(){
    vector<vector<int>> a{{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    vector<int> r = s.findDiagonalOrder(a);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
