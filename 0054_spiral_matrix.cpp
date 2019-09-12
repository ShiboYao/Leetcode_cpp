#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        int m = matrix.size();
        if (m == 0)
            return r;
        int n = matrix[0].size();
        int count = m * n;
        int i = 0, j = 0;
        int upper = -1, left = -1;
        while (1){
            while (j < n){
                r.push_back(matrix[i][j++]);
                count--;
            }
            if (!count)
                return r;
            j--;
            i++;
            upper++;
            while (i < m){
                r.push_back(matrix[i++][j]);
                count--;
            }
            if (!count)
                return r;
            i--;
            j--;
            n--;
            while (j > left){
                r.push_back(matrix[i][j--]);
                count--;
            }
            if (!count)
                return r;
            j++;
            i--;
            m--;
            while (i > upper){
                r.push_back(matrix[i--][j]);
                count--;
            }
            if (!count)
                return r;
            i++;
            j++;
            left++;
        }
    }
};



int main(){
    vector<vector<int>> a{{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    Solution s;
    vector<int> r = s.spiralOrder(a);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
