#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        for (int i = 0; i < numRows; i++){
            r.push_back(vector<int>(i+1));
            r[i][0] = 1;
            int mid = i/2;
            int a = 1;
            while (a <= mid){
                r[i][a] = r[i-1][a-1] + r[i-1][a];
                a++;
            }
            a--;
            int b = i%2?mid+1:mid;
            while (a >= 0)
                r[i][b++] = r[i][a--];
        }

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify num" << endl;
        exit(1);
    }
    int n = argv[1][0]-'0';
    Solution s;
    vector<vector<int>> r = s.generate(n);
    for (vector<int>& i : r){
        for (int& j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
