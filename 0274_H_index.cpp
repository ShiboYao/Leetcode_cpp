#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = citations.size()-1, h = 0;
        while (i >= 0 && h < citations[i]){
            i--;
            h++;
        }

        return h;
    }
};



int main(){
    vector<int> a{3,0,6,1,5};
    Solution s;
    cout << s.hIndex(a) << endl;

    return 0;
}
