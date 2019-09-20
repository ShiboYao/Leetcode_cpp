#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


class Solution {
    vector<int> a;
public:
    Solution(vector<int>& w) {
        a = w;
        for (int i = 1; i < a.size(); i++){
            a[i] = a[i] + a[i-1];
        }
    }

    int pickIndex() {
        srand(time(NULL));
        int r = rand()%a.back();
        int low = 0, high = a.size()-1, mid;
        while (low <= high){
            mid = (low+high)/2;
            if (a[mid] > r){
                if (mid == 0 || a[mid-1] <= r)
                    return mid;
                else
                    high = mid-1;
            }
            else {
                if (mid == a.size() || a[mid+1] > r)
                    return mid+1;
                else
                    low = mid+1;
            }
        }

        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */



int main(){
    vector<int> w{1000,1000,1};
    Solution* obj = new Solution(w);
    cout << obj->pickIndex() << endl;

    return 0;
}
