#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestArithSeqLength(vector<int>& A){
        int n = A.size(), diff, maxi = 1;
        vector<unordered_map<int,int>> memo(n);//save largest step number
        for (int i = 1; i < n; i++){           //for each diff at each position
            for (int j = 0; j < i; j++){
                diff = A[i] - A[j];
                memo[i][diff] = max(memo[j][diff]+1, memo[i][diff]);
                maxi = max(maxi, memo[i][diff]);
            }
        }

        return maxi+1;
    }
};



int main(){
    //vector<int> a{3,6,9,12};
    //vector<int> a{9,4,7,2,10};
    vector<int> a{20,1,15,3,10,5,8};
    Solution s;
    cout << s.longestArithSeqLength(a) << endl;

    return 0;
}
