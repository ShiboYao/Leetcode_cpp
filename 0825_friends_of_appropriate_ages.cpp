#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> a(121, 0);
        for (int& i : ages)
            a[i]++;
        vector<int> stack;
        int count = 0, pos = 0;
        for (int i = 15; i < 121; i++){
            if (a[i]){
                count += a[i] * (a[i]-1);
                int m = stack.size();
                while (pos < m && stack[pos] <= float(i*0.5 + 7))
                    pos++;
                for (int t = pos; t < m; t++)
                    count += a[i] * a[stack[t]];
                stack.push_back(i);
            }
        }

        return count;
    }
};



int main(){
    //vector<int> a{16, 16};
    //vector<int> a{16, 17, 18};
    //vector<int> a{20,30,100,110,120};
    //vector<int> a{8,85,24,85,69};
    //vector<int> a{118,14,7,63,103};
    vector<int> a{73,106,39,6,26,15,30,100,71,35,46,112,6,60,110};
    Solution s;
    cout << s.numFriendRequests(a) << endl;

    return 0;
}
