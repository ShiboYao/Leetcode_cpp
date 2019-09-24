#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> r(n);
        vector<vector<int>> stack;
        int i = 0;
        while (i < n){
            while (!stack.empty() && T[i] > stack.back()[0]){
                r[stack.back()[1]] = i - stack.back()[1];
                stack.pop_back();
            }
            stack.push_back({T[i],i});
            i++;
        }

        return r;
    }
};



int main(){
    vector<int> a{73,74,75,71,69,72,76,73};
    Solution s;
    vector<int> r = s.dailyTemperatures(a);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
