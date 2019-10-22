#include <iostream>
using namespace std;


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int a = 0, b = 0, c = 0, d = 0;
        while (b < S.size()){
            if (S[b] != '#') S[a++] = S[b];
            else a = max(0, a-1);
            b++;
        }
        while (d < T.size()){
            if (T[d] != '#') T[c++] = T[d];
            else c = max(0, c-1);
            d++;
        }

        return S.substr(0,a) == T.substr(0,c);
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str1 and str2" << endl;
        exit(1);
    }
    string S = argv[1], T = argv[2];
    Solution s;
    cout << s.backspaceCompare(S, T) << endl;

    return 0;
}
