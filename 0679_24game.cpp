#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    bool judgePoint24(vector<int>& A) {
        sort(A.begin(),A.end());
        do{
            if (go(A[0],A[1],A[2],A[3])) return true;
        } while (next_permutation(A.begin(),A.end()));
        
        return false;
    }
private:
    double e = 0.0001;

    bool go(double a, double b, double c, double d) {
        return
            go(a+b,c,d) || go(a-b,c,d) || go(a*b,c,d) || (b&&go(a/b,c,d)) ||
            go(a,b+c,d) || go(a,b-c,d) || go(a,b*c,d) || (c&&go(a,b/c,d)) ||
            go(a,b,c+d) || go(a,b,c-d) || go(a,b,c*d) || (d&&go(a,b,c/d));
    }
    bool go(double a, double b, double c){
        return
            go(a+b,c) || go(a-b,c) || go(a*b,c) || (b&&go(a/b,c)) ||
            go(a,b+c) || go(a,b-c) || go(a,b*c) || (c&&go(a,b/c));
    }
    bool go(double a, double b){
        return abs(a+b-24.0) < e || abs(a-b-24.0) < e || abs(a*b-24.0) < e || (b&&abs(a/b-24.0) < e);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify nums str" << endl;
        exit(1);
    }
    vector<int> a{argv[1][0]-'0',argv[1][1]-'0',argv[1][2]-'0',argv[1][3]-'0'};
    Solution s;
    cout << s.judgePoint24(a) << endl;

    return 0;
}
