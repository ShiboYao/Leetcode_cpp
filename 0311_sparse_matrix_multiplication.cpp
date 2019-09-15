#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), p = B.size(), n = B[0].size();
        vector<vector<int>> r;
        for (int i = 0; i < m; i++){
            vector<int> t;
            for (int j = 0; j < n; j++){
                int c = 0;
                for (int k = 0; k < p; k++){
                    if (A[i][k] && B[k][j])
                        c += A[i][k] * B[k][j];
                }
                t.push_back(c);
            }
            r.push_back(t);
        }

        return r;
    }
};



int main(){
    vector<vector<int>> A{{1,0,0}, {-1,0,3}};
    vector<vector<int>> B{{7,0,0}, {0,0,0}, {0,0,1}};
    Solution s;
    vector<vector<int>> r = s.multiply(A, B);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
