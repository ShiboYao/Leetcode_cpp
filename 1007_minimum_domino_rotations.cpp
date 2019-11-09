#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        for (int i = 0, a = 0, b = 0; i < n && (A[i]==A[0] || B[i]==A[0]); ++i){
            if (A[i] != A[0]) a++;
            if (B[i] != A[0]) b++;
            if (i == n-1) return min(a,b);
        }
        for (int i = 0, a = 0, b = 0; i < n && (A[i]==B[0] || B[i]==B[0]); ++i){
            if (A[i] != B[0]) a++;
            if (B[i] != B[0]) b++;
            if (i == n-1) return min(a,b);
        }

        return -1;
    }
};



int main(){
    //vector<int> a{2,1,2,4,2,2}, b{5,2,6,2,3,2};
    //vector<int> a{3,5,1,2,3}, b{3,6,3,3,4};
    vector<int> a{2,1,1,1,2,2,2,1,1,2}, b{1,1,2,1,1,1,1,2,1,1};
    Solution s;
    cout << s.minDominoRotations(a,b) << endl;

    return 0;
}
