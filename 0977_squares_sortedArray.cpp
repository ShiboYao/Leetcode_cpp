#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = A.size();
        vector<int> r(i);
        i--;
        int j = 0, k = i;
        while (i >= 0){
            if (abs(A[k]) >= abs(A[j]))
                r[i--] = A[k] * A[k--];
            else
                r[i--] = A[j] * A[j++];
        }

        return r;
    }
};



int main(){
    vector<int> a{-4,-1,0,3,10};
    Solution s;
    vector<int> b = s.sortedSquares(a);
    for (int& i : b)
        cout << i << " ";
    cout << endl;

    return 0;
}
