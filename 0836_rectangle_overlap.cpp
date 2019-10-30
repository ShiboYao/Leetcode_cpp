#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left = max(rec1[0],rec2[0]), right = min(rec1[2],rec2[2]), bottom = max(rec1[1],rec2[1]), up = min(rec1[3],rec2[3]);
        return right > left && up > bottom;
    }
};



int main(){
    //vector<int> a{0,0,2,2}, b{1,1,3,3};
    vector<int> a{0,0,1,1}, b{1,0,2,1};
    Solution s;
    cout << s.isRectangleOverlap(a,b) << endl;

    return 0;
}
