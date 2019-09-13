#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n <= 1)
            return true;
        int i = 1;
        while (i < n && A[i-1] == A[i])
            i++;
        if (i == n)
            return true;
        if (A[i-1] < A[i]){
            while (i < n && A[i-1] <= A[i])
                i++;
        }
        else {
            while (i < n && A[i-1] >= A[i])
                i++;
        }

        return i==n;
    }
};



int main(){
    vector<int> a{1,2,2,3};
    Solution s;
    cout << s.isMonotonic(a) << endl;

    return 0;
}
