#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, k = K;
        int max_len = 0;
        while (j < A.size()){
            if (A[j] == 1)
                j++;
            else {
                if (k > 0){
                    k--;
                    j++;
                }
                else {
                    if (A[i] == 0)
                        k++;
                    i++;
                }
            }
            max_len = max(max_len, j-i);
        }

        return max(max_len, j-i);
    }
};



int main(){
    vector<int> a{0,0,1,1,1,0,0};
    int k = 0;
    Solution s;
    cout << s.longestOnes(a, k) << endl;

    return 0;
}
