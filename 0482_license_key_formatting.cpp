#include <iostream>
#include <cctype>
using namespace std;


class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string re = "";
        int i = S.size()-1, c = 0;
        while(i >= 0){
            if (S[i] != '-'){
                re += toupper(S[i]);
                c++;
            }
            i--;
            if (i < 0) break;
            if (c == K){
                re += '-';
                c = 0;
            }
        }
        if (re.back() == '-')
            re = re.substr(0,re.size()-1);
        reverse(re.begin(), re.end());
        
        return re;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str and k" << endl;
        exit(1);
    }
    string S = argv[1];
    int k = argv[2][0]-'0';
    Solution s;
    cout << s.licenseKeyFormatting(S, k) << endl;

    return 0;
}
