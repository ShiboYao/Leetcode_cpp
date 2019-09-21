#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string toGoatLatin(string S) {
        int i = 0, j = 0, n = S.size();
        string r = "";
        int count = 1;
        while (i < n){
            while (j < n && S[j] != ' ')
                j++;
            char c = S[i];
            if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
                r += S.substr(i,j-i) + "ma" + string(count,'a');
            else {
                i++;
                r += S.substr(i,j-i) + c + "ma" + string(count,'a');
            }
            count++;
            i = ++j;
            r += ' ';
        }
        r = r.substr(0,r.size()-1);
        
        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.toGoatLatin(str) << endl;

    return 0;
}
