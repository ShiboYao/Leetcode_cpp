#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void util(int n, int k, vector<int> cur, vector<vector<int>>& r){
        if (k == 0){
            if (n >= 0)
                r.push_back(cur);
            return;
        }
        k--;
        for (int i = n; i > 0; i--){
            vector<int> pos = cur;
            pos.push_back(i);
            util(i-1,k,pos,r);
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> r;
        vector<int> cur;
        util(n,k,cur,r);

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str" << endl;
        exit(1);
    }
    int n = stoi(argv[1]), k = stoi(argv[2]);
    Solution s;
    vector<vector<int>> r = s.combine(n,k);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
