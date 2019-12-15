#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0) return 0;
        int low = 0, high = n-1, mid;
        while (low <= high){
            mid = (low+high)/2;
            int ind = n-mid;
            if (citations[mid] == ind)
                return ind;
            else if (citations[mid] > ind){
                if (mid == 0)
                    return ind;
                else if (citations[mid-1] < ind+1)
                    return ind;
                else
                    high = mid-1;
            }
            else {
                if (mid == n-1)
                    return min(1,citations[mid]);
                else if (citations[mid+1] > ind-1)
                    return ind-1;
                else
                    low = mid+1;
            }
        }

        return -1;
    }
};



int main(){
    //vector<int> a{0,1,3,5,6};
    vector<int> a{1,4,7,9};
    Solution s;
    cout << s.hIndex(a) << endl;

    return 0;
}
